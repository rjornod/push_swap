/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:31:26 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/07 15:06:37 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*string_input(t_stack *stack, char **argv)
{
	int		i;

	stack->digits = ft_split(argv[1], ' ');
	if (!stack->digits)
		error_message("Error assigning memory to digits in string_input");
	stack->digi_count = 0;
	while (stack->digits[stack->digi_count])
		stack->digi_count++;
	if (stack->digi_count == 1)
	{
		free_array(stack->digits);
		free(stack);
		error_message("Error only one digit in string input\n");
	}
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
	This function when called checks for duplicate characters on stack a
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
			error_message("number exists already");
		}
		j++;
	}
}

/*
	This function frees an array and all its individual allocations
	Using it mostly to free **digits
*/
void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
