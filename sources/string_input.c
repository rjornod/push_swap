/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:31:26 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/05 15:43:20 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*string_input(t_stack *stack, char **argv)
{
	int		i;
	stack->digits = ft_split(argv[1], ' ');
	if (!stack->digits)
		error_message("error assigning memory to digits in string_input");
	stack->digi_count = 0;
	while (stack->digits[stack->digi_count])
		stack->digi_count++;
	stack->elem_total = stack->digi_count;
	stack->stack_a = (int *)malloc((stack->elem_total) * sizeof(int));
	if (!stack->stack_a)
		return (free_array(stack->digits), NULL);
	i = 0;
	while (i < stack->elem_total)
	{
		if (check_valid_number(stack->digits[i]) == false)
		{
			error_message("Invalid number in string input\n");
			free(stack->stack_a); 
			free_array(stack->digits);
		}
		stack->stack_a[i] = ft_atoi(stack->digits[i]);
		i++;
	}
	free_array(stack->digits);
	return (stack->stack_a);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
