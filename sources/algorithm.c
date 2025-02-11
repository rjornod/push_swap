/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:49:20 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/11 17:11:14 by rojornod         ###   ########.fr       */
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
	push_b(stack);
	push_b(stack);
	push_b(stack);
	push_b(stack);
	push_b(stack);
	push_b(stack);
	push_b(stack);
	push_b(stack);
	print_stacks(stack);
	calculate_total_cost(stack);
	// while (i < stack->elem_count_a)
	// {
	// 	cost = get_cost(i, stack->elem_count_a);
	// 	if (cost < cheapest)
	// 	{
	// 		cheapest = cost;
	// 		cheapest_index = i;
	// 	}
	// 	ft_printf("the cost to move *%d* is [%d]\n", stack->stack_a[i], cost);
	// 	i++;
	// }
	//ft_printf("The cheapest to move is *%d* with [%d] moves", stack->stack_a[cheapest_index], cheapest);
	// while (!is_sorted(stack, stack->stack_a))
	// {
	// 	cost = get_cost(i, stack->elem_count_a);
	// 	ft_printf("The cost to move this character is: [%d]\n", cost);
	// 	if (stack->elem_count_a > 3)
	// 	{
	// 		push_b(stack);
	// 		push_b(stack);
	// 		ft_printf("pushed first two elements to b stack\n");
	// 		print_stacks(stack);
	// 	}
	// 	else
	// 		break ;
	// 	i++;
	// }
	// if (stack->elem_count_a == 3)
	// 	sort_three(stack);
	if (is_sorted(stack, stack->stack_a) && (stack->elem_count_a == stack->elem_total))
		return (ft_putendl_fd("Stack is sorted!",1));
	//ft_printf("elem count: [%d]\nelem total [%d]\n", stack->elem_count_a, stack->elem_total);
}

/*
	....... In progress .......
	This function will eventually be called when there are exactly
	three numbers in stack and will sort them
*/
void	sort_three(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->stack_a[i] > stack->stack_a[i + 1]
		&& stack->stack_a[i] > stack->stack_a[i + 2])
		ft_putendl_fd("first number is the biggest", 1);
}

/*
	This function checks if a given stack is sorted and returns true or false
*/

bool	is_sorted(t_stack *stack, int *sort_stack)
{
	int	i;

	i = 0;
	while (i < stack->elem_count_a - 1)
	{
		if (sort_stack[i] > stack->stack_a[i + 1])
			return (false);
		i++;
	}
	return (true);
}
