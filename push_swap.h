/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:35:41 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/18 15:07:54 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	errno.h for ERANGE: indicates a range error
	limits.h for INT MAX and INT MIN
*/
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"
#include <errno.h>
#include <limits.h>
#include <stdbool.h>

typedef struct s_stack
{
	int		*stack_b;
	int		*stack_a;
	char	**digits;
	int		digi_count;
	int		elem_total;
	int		elem_count_a;
	int		elem_count_b;
	int		a_max_elem;
	int		a_min_elem;
	int		a_max_index;
	int		a_min_index;
	int		cost_a;
	int		cost_b;
	int		cheapest_total;
	int		cheapest_index;
}	t_stack;

// Main
void	push_swap(t_stack *stack);
void	init_struct(t_stack *stack);
int		*init_stack_b(t_stack *stack);
bool	is_sorted(int *sort_stack, int elem_count);
void	sort_three(t_stack *stack);

// Validation
int		*validate_input(int argc, char **argv, t_stack *stack);
int		*one_arg(t_stack *stack, char **argv);
bool	check_valid_number(const char *str, t_stack *stack);
void	check_duplicate(t_stack *stack, int i);

// Operations
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	push_b(t_stack *stack);
void	push_a(t_stack *stack);
void	swap_a_b(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_a_b(t_stack *stack);
void	rev_rot_a(t_stack *stack);
void	rev_rot_b(t_stack *stack);
void	rev_rot_a_b(t_stack *stack);

// Cost calculations and moving
int		get_cost(int index, int size);
void	move_a_to_b(t_stack *stack);
void	move_b_to_a(t_stack *stack);
void	calculate_cheapest_b(t_stack *stack);
void	calculate_cheapest_a(t_stack *stack);

// Helper
int		ft_abs(int n);
void	error_message(char *message);
void	print_stacks(t_stack *stack);
void	free_array(char **array);
void	find_high_low_a(t_stack *stack, int *sort_stack, int elem_count);
