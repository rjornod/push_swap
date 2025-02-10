/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:35:41 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/10 16:53:59 by rojornod         ###   ########.fr       */
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
}	t_stack;

void	swap_stack_a(t_stack *stack);
void	swap_stack_b(t_stack *stack);
void	push_b(t_stack *stack);
void	push_a(t_stack *stack);
void	swap_a_b(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_a_b(t_stack *stack);
void	rev_rot_a(t_stack *stack);
void	rev_rot_b(t_stack *stack);
void	rev_rot_a_b(t_stack *stack);
int		*one_arg(t_stack *stack, char **argv);
void	free_array(char **array);
bool	check_valid_number(const char *str, t_stack *stack);
void	check_duplicate(t_stack *stack, int i);
void	push_swap(t_stack *stack);
void	error_message(char *message);
void	print_stacks(t_stack *stack);
void	print_stacks(t_stack *stack);
void	init_struct(t_stack *stack);
int		*init_stack_b(t_stack *stack);
bool	is_sorted(t_stack *stack, int *sort_stack);
void	sort_three(t_stack *stack);
void	find_high_low_a(t_stack *stack, int *sort_stack, int elem_count);
int		get_cost(int index, int size);
