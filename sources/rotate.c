/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:45:46 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/04 16:02:28 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
				operations meaning 
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

*/
void	rotate_a(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->elem_count_a < 2)
		return ;
	temp = stack->stack_a[0];
	i = 0;
	while (i < stack->elem_count_a - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[stack->elem_count_a - 1] = temp;
	ft_printf("ra\n");
}

void	rotate_b(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->elem_count_b < 2)
		return ;
	temp = stack->stack_b[0];
	i = 0;
	while (i < stack->elem_count_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[stack->elem_count_b - 1] = temp;
	ft_printf("rb\n");
}

void	rotate_a_b(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
	ft_printf("rr\n");
}

void	rev_rot_a(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->elem_count_b < 2)
		return ;
	i = stack->elem_count_a - 1;
	temp = stack->stack_a[i];
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = temp;
	ft_printf("rra\n");
}

void	rev_rot_b(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->elem_count_b < 2)
		return ;
	i = stack->elem_count_b - 1;
	temp = stack->stack_b[i];
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = temp;
	ft_printf("rrb\n");
}

void	rev_rot_a_b(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->elem_count_b < 2)
		return ;
	i = stack->elem_count_a - 1;
	temp = stack->stack_a[i];
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = temp;
	if (stack->elem_count_b < 2)
		return ;
	i = stack->elem_count_b - 1;
	temp = stack->stack_b[i];
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = temp;
	ft_printf("rrb\n");
}
