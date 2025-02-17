/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:49:20 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/17 17:15:00 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	....... In progress .......
	This function will eventually be the main algorithm (at some point)
*/
void	push_swap(t_stack *stack)
{
	int	i;
	int	j;
	int	cost;
	// int	cost_to_move;
	int	cheapest;
	int	cheapest_index;

	i = 0;
	j = 0;
	cost = 0;
	cheapest_index = 0;
	cheapest = cost;
	if (stack->elem_count_a > 3)
		push_b(stack);
	if (stack->elem_count_a > 3)
		push_b(stack);
	print_stacks(stack);
	// cheapest = calculate_cost(stack, i);
	i = stack->elem_count_a;
	while (stack->elem_count_a > 3)
	{
		calculate_cheapest(stack);
		print_stacks(stack);
		move_a_to_b(stack);
		ft_printf("-----------------------------------\n");
	}
	
	if (stack->elem_count_a == 3)
		sort_three(stack);
	print_stacks(stack);
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
	if (a > b && b < c && a< c)
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
	}
	return (true);
}
