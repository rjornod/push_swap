/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:49:20 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/06 17:46:43 by rojornod         ###   ########.fr       */
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
			ft_printf("pushed first two elements to b stack\n");
			print_stacks(stack);
		}
	}
	if (is_sorted(stack) && (stack->elem_count_a == stack->elem_total))
		ft_printf("\nstack is sorted\n");
	ft_printf("elem count: [%d]\nelem total [%d]\n", stack->elem_count_a, stack->elem_total);
}

bool	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->elem_count_a - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			return (false);
		i++;
	}
	return (true);
}