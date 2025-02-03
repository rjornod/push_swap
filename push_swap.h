/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:35:41 by rojornod          #+#    #+#             */
/*   Updated: 2025/02/03 17:01:44 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/get_next_line/get_next_line.h"
#include "libft/ft_printf/ft_printf.h"
#include <stdbool.h>

typedef struct s_stack
{
	int	*stack_b;
	int	*stack_a;
	int	elem_total;
	int	elem_count_a;
	int	elem_count_b;
}	t_stack;

void	swap_stack_a(t_stack *stack);
void	swap_stack_b(t_stack *stack);
void 	push_b(t_stack *stack);
void 	push_a(t_stack *stack);