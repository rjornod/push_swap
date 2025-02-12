/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:30:50 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/12 15:27:57 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
static int	find_target_index(t_stack *stack, int candidate)
{
	int	i;

	i = 0;
	while (i < stack->elem_count_b)
	{
		if (candidate > stack->stack_b[i])
			break ;
		i++;
	}
	return (i);
}

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
	....... In progress .......
	This function will calculate the total cost (cost_a + cost_b) of each
	candidate
*/
int	calculate_total_cost(t_stack *stack)
{
	int	cost_a;
	int	cost_b;
	int	abs_a;
	int	abs_b;
	int	target_b;
	int	i;
	int	total_cost;
	int	overlap;
	cost_b = 0;

	i = 0;
	while (i < stack->elem_count_a)
	{
		cost_a = get_cost(i, stack->elem_count_a);
		target_b = find_target_index(stack, stack->stack_a[i]);
		ft_printf("----------------------------------------------------\n");
		ft_printf("elem b count %d\n", stack->elem_count_b);
		ft_printf("target b count %d\n", target_b);
		cost_b = get_cost(target_b, stack->elem_count_b);
		
		ft_printf("\nFor index [%d] | number [%d]\ncost a: [%d]\ntarget b: [%d]\ncost b: [%d]\n", i, stack->stack_a[i], cost_a, target_b, cost_b);
		
		// total_cost = cost_a + cost_b;
		if ((cost_a < 0 && cost_b < 0) || (cost_a > 0 && cost_b > 0))
		{
			abs_a = ft_abs(cost_a);
			abs_b = ft_abs(cost_b);
			overlap = ft_min(abs_a, abs_b);
			ft_printf("overlap is [%d]\n", overlap);
			ft_printf("cost a [%d] | cost b [%d]\n", cost_a, cost_b);
			total_cost = (abs_a + abs_b) - overlap;
			
			ft_printf("both require the same rotations\n\n");
		}
		else
		{
			total_cost = cost_a + cost_b;
			ft_printf("total cost with no overlap is [%d]\n", total_cost);
		}
		ft_printf("the total cost to move [%d] is [%d]\n\n", stack->stack_a[i], total_cost);
		print_stacks(stack);
		i++;
	}
	return (0);
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


