/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:25:58 by rojornod          #+#    #+#             */
/*   Updated: 2025/01/31 17:25:38 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_message(char *message)
{
	ft_printf("%s", message);
	return (-1);
}

int sort_func(char **argv)
{
	int i;
	
	i = 1;
	while (argv[i])
	{
		ft_printf("%s\n", argv[i]);
		i++;
	}
	return (i);
}
bool check_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		str++;
	if (str[i] == '\0')
		return false;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
		{
			ft_printf("Error\n");
			return (false);
		}
		i++;
	}
	return (true);
}

int	*convert_input(int argc, char **argv)
{
	int *stack_a;
	int i;

	i = 1;
	
	stack_a = (int *)malloc(argc *sizeof(int));
	if (!stack_a)
		return (NULL);
	while (i < argc)
	{
		if (check_valid_number(argv[i]) == false)
			ft_printf("argument not valid\n");
		stack_a[i] = ft_atoi(argv[i]);
		i++;
	}
	i = 1;
	while (i < argc)
	{
		ft_printf("%d, ", stack_a[i]);
		i++;
	}
	ft_printf("\n");
	free(stack_a);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc < 2)
		error_message("you can't do that for now");
	else
		if (convert_input(argc, argv) < 0)
			error_message("Error\n");
}