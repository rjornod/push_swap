/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:30:50 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/23 16:34:08 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	....... In progress .......
	This function will calculate where best to put each candidate number from
	STACK A to STACK B. If it finds a number smaller than the candidate it
	breaks the loop, meaning the number should be inserted at this index
*/
static int	find_target_asc(int *stack, int elem_count, int candidate)
{
	int	i;
	int	target_index;
	int	best_diff;
	int	diff;

	target_index = -4000;
	best_diff = -4000;
	i = 0;
	while (i < elem_count)
	{
		if (stack[i] > candidate)
		{
			diff = candidate - stack[i];
			if (best_diff == -4000 || diff > best_diff)
			{
				best_diff = diff;
				target_index = i;
			}
		}
		i++;
	}
	if (target_index == -4000)
		target_index = 0;
	return (target_index);
}

/*
	Finds the target destination in Stack B for the candidate from Stack A
*/
static int	target_desc(int *stack, int elem_count, int candidate)
{
	int	i;
	int	target_index;
	int	best_diff;
	int	diff;

	i = 0;
	target_index = -1;
	best_diff = -1;
	while (i < elem_count)
	{
		if (stack[i] < candidate)
		{
			diff = candidate - stack[i];
			if (best_diff == -1 || diff < best_diff)
			{
				best_diff = diff;
				target_index = i;
			}
		}
		i++;
	}
	if (target_index == -1)
		target_index = 0;
	return (target_index);
}

/*
	....... In progress .......
	This function will calculate the total cost (cost_a + cost_b) of each
	candidate
*/
void	find_cheapest_a_to_b(t_stack *stack)
{
	int	i;
	int	cost_a;
	int	cost_b;
	int	target;
	int	total_cost;
	int	overlap;

	stack->cheapest_total = 100000;
	i = 0;
	while (i < stack->elem_count_a)
	{
		cost_a = get_cost(i, stack->elem_count_a);
		target = target_desc(stack->stack_b, 
				stack->elem_count_b, stack->stack_a[i]);
		cost_b = get_cost(target, stack->elem_count_b);
		if ((cost_a < 0 && cost_b < 0)
			|| (cost_a > 0 && cost_b > 0))
		{
			overlap = ft_min(ft_abs(cost_a), ft_abs(cost_b));
			total_cost = (ft_abs(cost_a) + ft_abs(cost_b)) - ft_abs(overlap);
		}
		else
			total_cost = ft_abs(cost_a) + ft_abs(cost_b);
		if (total_cost < stack->cheapest_total)
		{
			stack->cheapest_total = total_cost;
			stack->cost_a = cost_a;
			stack->cost_b = cost_b;
			stack->cheapest_index = i;
		}
		i++;
	}
}

void	find_cheapest_b_to_a(t_stack *stack)
{
	int	i;
	int	cost_a;
	int	cost_b;
	int	target_a;
	int	total_cost;
	int	overlap;

	stack->cheapest_total = 100000;
	i = 0;
	while (i < stack->elem_count_b)
	{
		target_a = find_target_asc(stack->stack_a, stack->elem_count_a, stack->stack_b[i]);
		cost_a = get_cost(target_a, stack->elem_count_a);
		cost_b = get_cost(i, stack->elem_count_b);
		if ((cost_a < 0 && cost_b < 0)
			|| (cost_a > 0 && cost_b > 0))
		{
			overlap = ft_min(ft_abs(cost_a), ft_abs(cost_b));
			total_cost = (ft_abs(cost_a) + ft_abs(cost_b)) - ft_abs(overlap);
		}
		else
			total_cost = ft_abs(cost_a) + ft_abs(cost_b);
		if (total_cost < stack->cheapest_total)
		{
			stack->cheapest_total = total_cost;
			stack->cost_a = cost_a;
			stack->cost_b = cost_b;
			stack->cheapest_index = i;
		}
		i++;
	}
}

/*
	This function calculates the cost of moving something to stack b based 
	on the position of the candidate.

	If index is on the top half: 
		return a positive number (rotation should be normal (ra));
	If index is on the bottom half:
		return a negative number (rotation should be reverse (rra));

	index: where the number sits on the stack;
	size: the amount of elements on that stack;
*/
int	get_cost(int index, int size)
{
	if (index <= size / 2)
		return (index);
	else
		return (index - size);
}
