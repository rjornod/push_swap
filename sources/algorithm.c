/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:49:20 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/07 17:39:19 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	This function will eventually be the main algorithm (at some point)
*/
void	push_swap(t_stack *stack)
{
	int	i;

	i = 0;
	while (!is_sorted(stack, stack->stack_a))
	{
		if (stack->elem_count_a > 3)
		{
			push_b(stack);
			push_b(stack);
			ft_printf("pushed first two elements to b stack\n");
			print_stacks(stack);
		}
		else
			break ;
	}
	if (stack->elem_count_a == 3)
		sort_three(stack);
	if (is_sorted(stack, stack->stack_a) && (stack->elem_count_a == stack->elem_total))
		ft_printf("\nstack is sorted\n");
	ft_printf("elem count: [%d]\nelem total [%d]\n", stack->elem_count_a, stack->elem_total);
}

/*
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
	This function will eventually calculate the cost of moving an element 
	to another stack and do the cheapest one
*/
void	calculate_cost(t_stack *stack, int *sort_stack)
{
	int	cost_rev;
	int	cost_norm;

	cost_norm = 0;
	cost_rev = 0;
	// cost_norm = stack->
}

/*
	This function finds the MIN and MAX numbers and their position
	on any given stack
*/
void	find_high_low(t_stack *stack, int *sort_stack, int elem_count)
{
	int	i;

	i = 0;
	stack->max_elem = sort_stack[i];
	stack->max_index = i;
	stack->min_elem = sort_stack[i];
	stack->min_index = i;
	ft_printf("Element count is [%d]\n", elem_count);
	while (i < elem_count)
	{
		if (sort_stack[i] > stack->max_elem)
		{
			stack->max_elem = sort_stack[i];
			stack->max_index = i;
		}
		else if (sort_stack[i] < stack->min_elem)
		{
			stack->min_elem = sort_stack[i];
			stack->min_index = i;
		}
		i++;
	}
	ft_printf("Mininum number is [%d]\n", stack->min_elem);
	ft_printf("Mininum index is [%d]\n", stack->min_index);
	ft_printf("Maximum number is [%d]\n", stack->max_elem);
	ft_printf("Maximum index is [%d]\n", stack->max_index);
	ft_printf("\n");
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
