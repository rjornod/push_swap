/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:30:50 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/18 17:37:40 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	This function finds the absolute value of a number. 
	ex: if its negative it becomes positive
*/
int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

/*
	This function returns the minimum number of 2
*/
int ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
/*
	This function finds the MIN and MAX numbers and their position
	on any given stack
*/
void	find_high_low_a(t_stack *stack, int *sort_stack, int elem_count)
{
	int	i;

	i = 0;
	stack->a_max_elem = sort_stack[i];
	stack->a_max_index = i;
	stack->a_min_elem = sort_stack[i];
	stack->a_min_index = i;
	while (i < elem_count)
	{
		if (sort_stack[i] > stack->a_max_elem)
		{
			stack->a_max_elem = sort_stack[i];
			stack->a_max_index = i;
		}
		else if (sort_stack[i] < stack->a_min_elem)
		{
			stack->a_min_elem = sort_stack[i];
			stack->a_min_index = i;
		}
		i++;
	}
	ft_printf("Mininum number is [%d]\n", stack->a_min_elem);
	ft_printf("Mininum index is [%d]\n", stack->a_min_index);
	ft_printf("Maximum number is [%d]\n", stack->a_max_elem);
	ft_printf("Maximum index is [%d]\n\n", stack->a_max_index);
}

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

	target_index = -1;
	best_diff = -1;

	i = 0;
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
static int	find_target_des(int *stack, int elem_count, int candidate) 
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
		if (stack[i] > candidate)
		{
			diff = stack[i] - candidate;
			if (best_diff == -1 || diff < best_diff)
			{
				best_diff = diff;
				target_index = i;
			}
		}
		i++;
	}
	if (target_index == -1)
	{
		target_index = 0;
	}
	else
		target_index = target_index + 1;
	ft_printf("for candidate [%d] ", candidate);
	ft_printf("the target index is [%d]", target_index);
	return (target_index);
}

/*
	....... In progress .......
	This function will calculate the total cost (cost_a + cost_b) of each
	candidate
*/
void	calculate_cheapest_b(t_stack *stack)
{
	int	i;
	int	cost_a;
	int	cost_b;
	int	target_b;
	int	total_cost;
	int	abs_cost;
	int	overlap;

	stack->cheapest_total = 100000;
	i = 0;
	while (i < stack->elem_count_a)
	{
		cost_a = get_cost(i, stack->elem_count_a);
		target_b = find_target_des(stack->stack_b, stack->elem_count_b, stack->stack_a[i]);
		cost_b = get_cost(target_b, stack->elem_count_b);
		if ((cost_a < 0 && cost_b < 0) 
			|| (cost_a > 0 && cost_b > 0))
		{
			overlap = ft_min(cost_a, cost_b);
			total_cost = (cost_a + cost_b) - overlap;
			ft_printf("overlap is [%d]\n", overlap);
			ft_printf("cost a is [%d]\n", cost_a);
			ft_printf("cost b is [%d]\n", cost_b);
			ft_printf("total cost is [%d]\n", total_cost);
		}
		else{
			total_cost = cost_a + cost_b;
			ft_printf("total cost is [%d]\n", total_cost);}
		abs_cost = ft_abs(total_cost);
		if(abs_cost < stack->cheapest_total)
		{
			stack->cheapest_total = abs_cost;
			stack->cost_a = cost_a;
			stack->cost_b = cost_b;
			stack->cheapest_index = i;
		}
		i++;
	}
	ft_printf("the cheapest is [%d]\n", stack->stack_a[stack->cheapest_index]);
	ft_printf("cheapest cost is [%d]\n", stack->cheapest_total);
	ft_printf("cheapest cost rotation for a is [%d]\n", stack->cost_a);
	ft_printf("cheapest cost rotation for b is [%d]\n", stack->cost_b);
	ft_printf("the index for the cheapest is [%d]\n", stack->cheapest_index);
}

void	calculate_cheapest_a(t_stack *stack)
{
	int	i;
	int	cost_a;
	int	cost_b;
	int	target_a;
	int	total_cost;
	int	abs_cost;
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
			overlap = ft_min(cost_a, cost_b);
			total_cost = (cost_a + cost_b) - overlap;
		}
		else
			total_cost = cost_a + cost_b;
		abs_cost = ft_abs(total_cost);
		if(abs_cost < stack->cheapest_total)
		{
			stack->cheapest_total = abs_cost;
			stack->cost_a = cost_a;
			stack->cost_b = cost_b;
			stack->cheapest_index = i;
		}
		i++;
	}
	ft_printf("the cheapest is [%d]\n", stack->stack_b[stack->cheapest_index]);
	ft_printf("cheapest cost is [%d]\n", stack->cheapest_total);
	ft_printf("cheapest cost rotation for a is [%d]\n", stack->cost_a);
	ft_printf("cheapest cost rotation for b is [%d]\n", stack->cost_b);
	ft_printf("the index for the cheapest is [%d]\n", stack->cheapest_index);
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



