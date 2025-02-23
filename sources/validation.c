/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:51:19 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/23 16:41:58 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	This functions checks each argument given to see if its a valid number.
	Returns true or false
*/
bool	check_valid_number(const char *str, t_stack *stack)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		str++;
	if (str[i] == '\0')
		return (false);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
		{
			free(stack->stack_a);
			free_array(stack->digits);
			free(stack);
			error_message("Error\n");
		}
		i++;
	}
	return (true);
}

/*
	This function checks how many arguments have been passed, if its 2 it calls
	one_arg, if more it figures out the size of the stack, allocates 
	enough memory for it and checks one by one if all arguments are 
	valid digits. returns stack_a if it passes all the checks
*/
int	*validate_input(int argc, char **argv, t_stack *stack)
{
	int	i;

	if (argc == 2)
	{
		if (one_arg(stack, argv) == NULL)
			error_message("Error\n");
	}
	else
	{
		stack->elem_total = argc - 1;
		stack->stack_a = (int *)malloc((stack->elem_total) * sizeof(int));
		if (!stack->stack_a)
			error_message("Error\n");
		i = 0;
		while (i < stack->elem_total)
		{
			check_valid_number(argv[i + 1], stack);
			validate_min_max(stack, argv[i + 1]);
			stack->stack_a[i] = ft_atoi(argv[i + 1]);
			check_duplicate(stack, i);
			i++;
		}
	}
	return (stack->stack_a);
}

int	*one_arg(t_stack *stack, char **argv)
{
	int		i;

	stack->digits = ft_split(argv[1], ' ');
	if (!stack->digits)
		return (free(stack), error_message("Error\n"), NULL);
	stack->digi_count = 0;
	while (stack->digits[stack->digi_count])
		stack->digi_count++;
	if (stack->digi_count == 1)
		return (free_array(stack->digits), free(stack),
			error_message("Error\n"), NULL);
	stack->elem_total = stack->digi_count;
	stack->stack_a = (int *)malloc((stack->elem_total) * sizeof(int));
	if (!stack->stack_a)
		return (free_array(stack->digits), NULL);
	i = 0;
	while (i < stack->elem_total)
	{
		check_valid_number(stack->digits[i], stack);
		stack->stack_a[i] = ft_atoi(stack->digits[i]);
		check_duplicate(stack, i);
		i++;
	}
	free_array(stack->digits);
	return (stack->stack_a);
}

/*
	This function is called when validating the arguments given
	and it checks for duplicate characters on stack a
*/
void	check_duplicate(t_stack *stack, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (stack->stack_a[i] == stack->stack_a[j])
		{
			free(stack->stack_a);
			free_array(stack->digits);
			free(stack);
			error_message("Error\n");
		}
		j++;
	}
}

void	validate_min_max(t_stack *stack, const char *str)
{
	long long	num;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		if (sign == 1 && num > 2147483647)
		{
			free(stack->stack_a);
			free_array(stack->digits);
			free(stack);
			error_message("Error\n");
		}
		if (sign == -1 && (-num) < -2147483648)
		{
			free(stack->stack_a);
			free_array(stack->digits);
			free(stack);
			error_message("Error\n");
		}
		i++;
	}
}
