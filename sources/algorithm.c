/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:49:20 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/19 16:12:56 by rojornod         ###   ########.fr       */
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
		return(ft_printf("stack is already sorted\n"), exit(EXIT_SUCCESS));
	if (stack->elem_count_a > 3)
		push_b(stack);
	if (stack->elem_count_a > 3)
		push_b(stack);
	print_stacks(stack);
	// while (!is_sorted(stack->stack_a, stack->elem_count_a))
	// {
		while (stack->elem_count_a > 3)
		{
			find_cheapest_a_to_b(stack);
			move_a_to_b(stack);
			print_stacks(stack);
			ft_printf("------------------------------------------------------\n");
		}
		if (stack->elem_count_a == 3)
			sort_three(stack);
		while (stack->elem_count_b > 0)
		{
			find_cheapest_b_to_a(stack);
			move_b_to_a(stack);
			print_stacks(stack);
			ft_printf("------------------------------------------------------\n");
		}
	//}
	print_stacks(stack);
	ft_printf("sorted");
}

void	move_a_to_b(t_stack *stack)
{
	while (stack->cost_a > 0 && stack->cost_b > 0)
	{
		ft_printf("move a to b cost a is [%d]\n", stack->cost_a);
		ft_printf("move a to b cost b is [%d]\n", stack->cost_b);
		rotate_a_b(stack);
		stack->cost_a--;
		stack->cost_b--;
	}
	while (stack->cost_a < 0 && stack->cost_b < 0)
	{
		ft_printf("move a to b cost a is [%d]\n", stack->cost_a);
		ft_printf("move a to b cost b is [%d]\n", stack->cost_b);
		rev_rot_a_b(stack);
		stack->cost_a++;
		stack->cost_b++;
	}
	while (stack->cost_a > 0)
	{
		ft_printf("move a to b cost a is [%d]\n", stack->cost_a);
		ft_printf("move a to b cost b is [%d]\n", stack->cost_b);
		rotate_a(stack);
		stack->cost_a--;
	}
	while (stack->cost_a < 0)
	{
		ft_printf("move a to b cost a is [%d]\n", stack->cost_a);
		ft_printf("move a to b cost b is [%d]\n", stack->cost_b);
		rev_rot_a(stack);
		stack->cost_a++;
	}
	while (stack->cost_b < 0)
	{
		ft_printf("move a to b cost a is [%d]\n", stack->cost_a);
		ft_printf("move a to b cost b is [%d]\n", stack->cost_b);
		rev_rot_b(stack);
		stack->cost_b++;
	}
	while (stack->cost_b > 0)
	{
		rotate_b(stack);
		ft_printf("move a to b cost a is [%d]\n", stack->cost_a);
		ft_printf("move a to b cost b is [%d]\n", stack->cost_b);
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
		i++;
	}
	return (true);
}
