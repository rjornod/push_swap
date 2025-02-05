/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:35:41 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/05 15:05:18 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"
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
int		*string_input(t_stack *stack, char **argv);
void	free_array(char **array);
bool	check_valid_number(const char *str);
void	error_message(char *message);
