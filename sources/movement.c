/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:29:45 by roberto           #+#    #+#             */
/*   Updated: 2025/02/23 16:32:34 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	simultaneous_rotations(t_stack *stack)
{
	while (stack->cost_a > 0 && stack->cost_b > 0)
	{
		rotate_a_b(stack);
		stack->cost_a--;
		stack->cost_b--;
	}
	while (stack->cost_a < 0 && stack->cost_b < 0)
	{
		rev_rot_a_b(stack);
		stack->cost_a++;
		stack->cost_b++;
	}
}

static void	indivual_rotations(t_stack *stack)
{
	while (stack->cost_a > 0)
	{
		rotate_a(stack);
		stack->cost_a--;
	}
	while (stack->cost_a < 0)
	{
		rev_rot_a(stack);
		stack->cost_a++;
	}
	while (stack->cost_b < 0)
	{
		rev_rot_b(stack);
		stack->cost_b++;
	}
	while (stack->cost_b > 0)
	{
		rotate_b(stack);
		stack->cost_b--;
	}
}

void	move_a_to_b(t_stack *stack)
{
	simultaneous_rotations(stack);
	indivual_rotations(stack);
	push_b(stack);
}

void	move_b_to_a(t_stack *stack)
{
	simultaneous_rotations(stack);
	indivual_rotations(stack);
	push_a(stack);
}

void	final_rotate(t_stack *stack)
{
	int	min;

	if (stack->stack_a[0] != stack->a_min_elem)
	{
		find_high_low_a(stack, stack->stack_a, stack->elem_count_a);
		min = get_cost(stack->a_min_index, stack->elem_count_a);
		if (min > 0)
		{
			while (stack->stack_a[0] != stack->a_min_elem)
				rotate_a(stack);
		}
		else
		{
			while (stack->stack_a[0] != stack->a_min_elem)
				rev_rot_a(stack);
		}
	}
}
