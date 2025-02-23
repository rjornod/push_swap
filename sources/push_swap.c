/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:25:58 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/23 16:39:36 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	ft_printf("rrr\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = NULL;
	if (argc == 1)
		return (-1);
	stack = malloc(sizeof(t_stack));
	ft_memset(stack, 0, sizeof(t_stack));
	if (!stack)
		error_message("Error\n");
	stack->digits = NULL;
	if (validate_input(argc, argv, stack) == NULL)
		error_message("Error\n");
	init_struct(stack);
	init_stack_b(stack);
	push_swap(stack);
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
	return (0);
}
