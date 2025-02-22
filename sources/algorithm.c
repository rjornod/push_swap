/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:49:20 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/22 16:06:18 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	....... In progress .......
	This function will eventually be the main algorithm (at some point)
*/
void	push_swap(t_stack *stack)
{
	if (is_sorted(stack->stack_a, stack->elem_count_a))
		return (ft_printf("stack is already sorted\n"), exit(EXIT_SUCCESS));
	if (stack->elem_count_a > 3)
		push_b(stack);
	if (stack->elem_count_a > 3)
		push_b(stack);
	while (!is_sorted(stack->stack_a, stack->elem_total))
	{
		while (stack->elem_count_a > 3)
		{
			find_cheapest_a_to_b(stack);
			move_a_to_b(stack);
		}
		if (stack->elem_count_a == 3)
			sort_three(stack);
		while (stack->elem_count_b > 0)
		{
			find_cheapest_b_to_a(stack);
			move_b_to_a(stack);
		}
		final_rotate(stack);
	}
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

void	move_a_to_b(t_stack *stack)
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
	push_b(stack);
}

void	move_b_to_a(t_stack *stack)
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
	push_a(stack);
}

/*
	DONE
	This function gets called when there are exactly three numbers in stack 
	and will sort them. There is a different if	condition for all the 
	different cases possible. In the end the stack will b sorted
*/
void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->stack_a[0];
	b = stack->stack_a[1];
	c = stack->stack_a[2];
	if (a < b && b < c)
		return ;
	if (a > b && b < c && a < c)
		swap_a(stack);
	else if (a > b && b > c)
	{
		swap_a(stack);
		rev_rot_a(stack);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack);
	else if (a < b && b > c && a < c)
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (a < b && b > c && a > c)
		rev_rot_a(stack);
}

/*
	This function checks if a given stack is sorted and returns true or false
*/

bool	is_sorted(int *sort_stack, int elem_count)
{
	int	i;

	i = 0;
	while (i < elem_count - 1)
	{
		if (sort_stack[i] > sort_stack[i + 1])
			return (false);
		i++;
	}
	return (true);
}
