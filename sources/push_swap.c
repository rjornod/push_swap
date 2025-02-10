/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:25:58 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/10 16:54:19 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	This functions checks each argument given to see if its a valid number.
	Returns true or false
*/
bool	check_valid_number(const char *str, t_stack *stack)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		str++;
	if (str[i] == '\0')
		return (false);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
		{
			free(stack->stack_a); 
			free_array(stack->digits);
			free(stack);
			error_message("Invalid number in check valid input\n");
		}
		i++;
	}
	return (true);
}

/*
	This function checks how many arguments have been passed, if its 2 it calls
	one_arg, if more it figures out the size of the stack, allocates 
	enough memory for it and checks one by one if all arguments are 
	valid digits. returns stack_a if it passes all the checks
*/
int	*convert_input(int argc, char **argv, t_stack *stack)
{
	int	i;

	if (argc == 2)
	{		
		if(one_arg(stack, argv) == NULL)
			error_message("Error\n");
	}
	else
	{
		stack->elem_total = argc - 1;
		stack->stack_a = (int *)malloc((stack->elem_total) * sizeof(int));
		if (!stack->stack_a)
			error_message("error assigning memory to stack_a in conver input");
		i = 0;
		while (i < stack->elem_total)
		{
			check_valid_number(argv[i + 1], stack);
			stack->stack_a[i] = ft_atoi(argv[i + 1]);
			check_duplicate(stack, i);
			i++;
		}
	}
	return (stack->stack_a);
}

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
	
	if (convert_input(argc, argv, stack) == NULL)
			error_message("Error\n");
	init_struct(stack);
	ft_printf("\n\nPrinting original stacks\n");
	init_stack_b(stack);
	print_stacks(stack);
	// find_high_low_a(stack, stack->stack_a, stack->elem_count_a);

	push_swap(stack);
	
	ft_printf("\n\nPrinting stacks after first push\n");
	print_stacks(stack);
	// ft_printf("\n\nFinding MIN AND MAX  in Stack A\n");
	// find_high_low_a(stack, stack->stack_a, stack->elem_count_a);
	// ft_printf("\n\nFinding MIN AND MAX  in Stack B\n");
	// find_high_low_a(stack, stack->stack_b, stack->elem_count_b);
	// ft_printf("\n----------Elem count of A is : %d--------------", stack->elem_count_a);
	// ft_printf("\n\nSwapping first 2 elements in stack A\n");
	// swap_stack_a(stack);
	// print_stacks(stack);

	// ft_printf("\n\nPushing A twice\n");
	// push_b(stack);
	// push_b(stack);
	// //ft_printf("\n\nAssigning 8 to the first element of stack b\n");
	// // stack->stack_b[0] = 8;
	// // stack->stack_b[1] = 1;
	// print_stacks(stack);

	// ft_printf("\n\nSwapping first 2 elements in stack B\n");
	// swap_stack_b(stack);
	// print_stacks(stack);

	// ft_printf("\n\nPushing first element of A to B\n");
	// push_b(stack);
	// print_stacks(stack);

	// ft_printf("\n\nPushing first element of B to A\n");
	// push_a(stack);
	// print_stacks(stack);

	// ft_printf("\n\nSwapping A and B at the same time\n");
	// swap_a_b(stack);
	// print_stacks(stack);

	// ft_printf("\n\nRotating A, first element becomes last\n");
	// rotate_a(stack);
	// print_stacks(stack);
	
	// print_stacks(stack);
	// ft_printf("\n\nRotating B, first element becomes last\n");
	// rotate_b(stack);
	// print_stacks(stack);

	// ft_printf("\n\nRotating both at the same time, first element becomes last\n");
	// rotate_a_b(stack);
	// print_stacks(stack);
	
	// ft_printf("\n\nRev Rotating A, last element becomes first\n");
	// rev_rot_a(stack);
	// print_stacks(stack);

	// ft_printf("\n\nRev Rotating B, last element becomes first\n");
	// rev_rot_b(stack);
	// print_stacks(stack);

	// ft_printf("\n\nRev Rotating A and B, last element becomes first\n");
	// rev_rot_a_b(stack);
	// print_stacks(stack);

	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
	return (0);
}
