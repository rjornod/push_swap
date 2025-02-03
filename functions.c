/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:19:49 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/03 17:00:01 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack_a(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->stack_a || stack->elem_count_a < 2)
		return;
	temp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = temp;
}

void	swap_stack_b(t_stack *stack)
{
	int	temp;
	stack->elem_count_b = 2;
	if (!stack || !stack->stack_b ||  stack->elem_count_b < 2)
		return;
	temp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = temp;
}

void swap_a_b(t_stack *stack)
{
	swap_stack_a(stack);
	swap_stack_b(stack);
}

void push_a(t_stack *stack)
{
	int i;

	if (!stack || !stack->stack_b || !stack->stack_a || stack->elem_count_b < 1)
		return;
	stack->stack_a[3] = 0;
	i = stack->elem_count_a;
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = stack->stack_b[0];
	i = 0;
	while (i < stack->elem_count_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->elem_count_a++;
	stack->elem_count_b--;
}

void push_b(t_stack *stack)
{
	int i;

	if (!stack || !stack->stack_b || !stack->stack_a || stack->elem_count_a < 1)
		return;
	stack->stack_a[3] = 0;
	i = stack->elem_count_b;
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = stack->stack_a[0];
	i = 0;
	while (i < stack->elem_count_a - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->elem_count_b++;
	stack->elem_count_a--;
}