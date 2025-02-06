/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:49:20 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/06 17:30:42 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_stack *stack)
{
	while (!is_sorted(stack))
	{
		if (stack->elem_count_a > 3)
		{
			push_b(stack);
			push_b(stack);
			ft_printf("pushed first two elements to b stack");
			print_stacks(stack);
		}
	}
	if (is_sorted(stack) && (stack->elem_count_a == stack->elem_total))
		ft_printf("\nstack is sorted\n");
	ft_printf("elem count: [%d]\nelem total [%d]", stack->elem_count_a, stack->elem_total);
}

bool	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->elem_count_a)
	{
		if (stack->stack_a[i] < stack->stack_a[i + 1])
		if (i == stack->elem_count_a)
			return (true);
		i++;
	}
	return (false);
}