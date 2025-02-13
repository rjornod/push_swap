/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:25:58 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/13 11:51:38 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack = NULL;
	if (argc == 1)
		return (-1);

	ft_printf("Initialzing stack to null...\n");
	
	ft_printf("Mallocing stack...\n");
	stack = malloc(sizeof(t_stack));
	if (!stack)
		error_message("Error assigning memory in main");
	ft_printf("Stack initialized!\n");
	ft_memset(stack, 0, sizeof(t_stack));
	ft_printf("Malloc successful\n");
	stack->digits = NULL;
	
	ft_printf("Assigned successfully!\n");
	
	if (validate_input(argc, argv, stack) == NULL)
			error_message("Error\n");
	init_struct(stack);
	ft_printf("\n\nPrinting original stacks\n");
	init_stack_b(stack);
	print_stacks(stack);
	// find_high_low_a(stack, stack->stack_a, stack->elem_count_a);

	push_swap(stack);
	
	ft_printf("\n\nPrinting stacks after first push\n");
	print_stacks(stack);

	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
	return (0);
}
