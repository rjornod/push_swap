/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:25:58 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/04 17:33:24 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error_message(char *message)
{
	ft_printf("%s", message);
	return (-1);
}

bool	check_valid_number(const char *str)
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
			return (ft_printf("is digit: FALSE\n"), false);
		i++;
	}
	return (true);
}

int	*init_stack_b(t_stack *stack, int argc)
{
	int	i;
	i = 0;
	stack->stack_b = (int *)ft_calloc((argc - 1), sizeof (int));
	if (!stack->stack_b)
		return (NULL);
	
	return (stack->stack_b);
}
void	print_stacks(t_stack *stack, int argc)
{
	int	i;

	i = 0;
	ft_printf("\nStack A\n");
	while (i < argc - 1)
	{
		ft_printf("[%d] ", stack->stack_a[i]);
		i++;
	}
	i = 0;
	ft_printf("\nStack B\n");
	while (i < argc - 1)
	{
		ft_printf("[%d] ", stack->stack_b[i]);
		i++;
	}
}


int	*convert_input(int argc, char **argv, t_stack *stack)
{
	int	i;

	stack->stack_a = (int *)malloc((argc - 1) * sizeof(int));
	if (!stack->stack_a)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		if (check_valid_number(argv[i + 1]) == false)
			return (ft_printf("Invalid number\n"), free(stack->stack_a), NULL);
		stack->stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (stack->stack_a);
}


void	init_struct(t_stack *stack)
{
	stack->elem_count_a = stack->elem_total;
	stack->elem_count_b = 0;
}
// void	push_swap(t_stack *stack)
// {
// 	while (stack->stack_a)
// 	{
// 		if(stack->elem_count_a == 3)
// 		{
// 			ft_printf("\n\n ***** there are 3 elements on stack A ******");
// 		}
// 	}
// }

int	*string_input(t_stack *stack, int argc, char **argv)
{
	char	**digits;
	int		i;
	
	(void)argc;
	digits = ft_split(argv[1], ' ');
	if (!digits)
		ft_printf("error, invalid numbers");
	i = 0;
	while (digits[i])
	{
		if (!check_valid_number(digits[i]))
			ft_printf("Error\n");
		else
			ft_printf("valid number");
		i++;
	}
	return (stack->stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack = NULL;
	if (argc < 2)
		error_message("You can't do that for now");
	if (argc == 2)
		string_input(stack, argc, argv);
	ft_printf("Initialzing stack to null...\n");
	ft_printf("Stack initialized!\n");
	
	ft_printf("Mallocing stack...\n");
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (-1);
	ft_printf("Malloc successful\n");
	
	ft_printf("Assigning argc -1 to element count...\n");
	stack->elem_total = (argc - 1);
	ft_printf("Elem total is [%d]...\n", stack->elem_total);
	init_struct(stack);
	ft_printf("Assigned successfully!\n");
	
	if (convert_input(argc, argv, stack) == NULL)
			error_message("Error\n");

	ft_printf("\n\nPrinting original stacks\n");
	init_stack_b(stack, argc);
	print_stacks(stack, argc);

	ft_printf("\n----------Elem count of A is : %d--------------", stack->elem_count_a);
	ft_printf("\n\nSwapping first 2 elements in stack A\n");
	swap_stack_a(stack);
	print_stacks(stack, argc);

	ft_printf("\n\nAssigning 8 to the first element of stack b\n");
	stack->stack_b[0] = 8;
	stack->stack_b[1] = 1;
	print_stacks(stack, argc);

	ft_printf("\n\nSwapping first 2 elements in stack B\n");
	swap_stack_b(stack);
	print_stacks(stack, argc);

	ft_printf("\n\nPushing first element of A to B\n");
	push_b(stack);
	print_stacks(stack, argc);

	ft_printf("\n\nPushing first element of B to A\n");
	push_a(stack);
	print_stacks(stack, argc);

	ft_printf("\n\nSwapping A and B at the same time\n");
	swap_a_b(stack);
	print_stacks(stack, argc);

	ft_printf("\n\nRotating A, first element becomes last\n");
	rotate_a(stack);
	print_stacks(stack, argc);
	
	ft_printf("\n\nPushing A twice\n");
	push_b(stack);
	push_b(stack);
	print_stacks(stack, argc);
	ft_printf("\n\nRotating B, first element becomes last\n");
	rotate_b(stack);
	print_stacks(stack, argc);

	ft_printf("\n\nRotating both at the same time, first element becomes last\n");
	rotate_a_b(stack);
	print_stacks(stack, argc);
	
	ft_printf("\n\nRev Rotating A, last element becomes first\n");
	rev_rot_a(stack);
	print_stacks(stack, argc);

	ft_printf("\n\nRev Rotating B, last element becomes first\n");
	rev_rot_b(stack);
	print_stacks(stack, argc);

	ft_printf("\n\nRev Rotating A and B, last element becomes first\n");
	rev_rot_a_b(stack);
	print_stacks(stack, argc);

	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
}
