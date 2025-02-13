/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:49:20 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/13 17:31:37 by rojornod         ###   ########.fr       */
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
	int	cost;
	int	cheapest;
	int	cheapest_index;

	i = 0;
	cost = 0;
	cheapest_index = 0;
	cheapest = cost;
	if (stack->elem_count_a > 3)
		push_b(stack);
	if (stack->elem_count_a > 3)
		push_b(stack);
	if (stack->elem_count_a == 3)
		sort_three(stack);
	print_stacks(stack);
	cheapest = calculate_cheapest(stack, i);
	while (++i < stack->elem_count_a)
	{
		cost = calculate_cheapest(stack, i);
		if (cost < cheapest)
		{
			cheapest = cost;
			cheapest_index = i;
		}
	}
	ft_printf("the cheapest is index [%d] with [%d] moves", cheapest_index, cheapest);
	move_a_to_b(stack, cheapest_index, cheapest);
	print_stacks(stack);
}

void	move_a_to_b(t_stack *stack, int cheapest_index, int cheapest)
{
	ft_printf("\ninsde move a to b\n");
	ft_printf("\ncost is [%d]\n", cheapest);
	(void)cheapest_index;
	if (cheapest == 0)
		swap_a(stack);
	else if (cheapest < 0)
	{
		rev_rot_a(stack);
		swap_a(stack);
	}
	else if (cheapest > 0)
	{
		rotate_a(stack);
		swap_a(stack);
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
