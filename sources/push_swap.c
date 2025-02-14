/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:25:58 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/14 14:44:59 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack = NULL;
	if (argc == 1)
		return (-1);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		error_message("Error assigning memory in main");
	ft_memset(stack, 0, sizeof(t_stack));
	stack->digits = NULL;
	if (validate_input(argc, argv, stack) == NULL)
			error_message("Error\n");
	init_struct(stack);
	init_stack_b(stack);
	print_stacks(stack);
	push_swap(stack);
	print_stacks(stack);
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
	return (0);
}
