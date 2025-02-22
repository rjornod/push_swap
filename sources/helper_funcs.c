/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:54:23 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/22 14:44:59 by roberto          ###   ########.fr       */
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
	stack->stack_b = (int *)ft_calloc((stack->elem_total), sizeof (int));
	if (!stack->stack_b)
		error_message("Error\n");
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
	ft_printf("\n\n");
}

//before finishing comment out the fprintf and use write
void	error_message(char *message)
{
	write(2, message, 6);
	exit(EXIT_FAILURE);
}

/*
	This function frees an array and all its individual allocations
	Using it mostly to free **digits
*/
void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
