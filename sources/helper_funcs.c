/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:54:23 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/06 16:21:43 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_struct(t_stack *stack)
{
	stack->elem_count_a = stack->elem_total;
	stack->elem_count_b = 0;
}

int	*init_stack_b(t_stack *stack)
{
	int	i;

	i = 0;
	stack->stack_b = (int *)ft_calloc((stack->elem_total), sizeof (int));
	if (!stack->stack_b)
		error_message("error assigning memory to stack b in init_stack_b");
	return (stack->stack_b);
}

void	print_stacks(t_stack *stack)
{
	int	i;

	i = 0;
	ft_printf("\nStack A\n");
	while (i < stack->elem_total)
	{
		ft_printf("[%d] ", stack->stack_a[i]);
		i++;
	}
	i = 0;
	ft_printf("\nStack B\n");
	while (i < stack->elem_total)
	{
		ft_printf("[%d] ", stack->stack_b[i]);
		i++;
	}
}

void	error_message(char *message)
{
	ft_printf("%s", message);
	exit(EXIT_FAILURE);
}
