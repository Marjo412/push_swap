/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:24:37 by mrosset           #+#    #+#             */
/*   Updated: 2025/04/16 17:45:04 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# include "libft.h"
# include "ft_printf.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

/*moves*/
void	swap(t_stack *stack);
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_ss(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack **dest, t_stack **src);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_rr(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_rr(t_stack **stack_a, t_stack **stack_b);

/*init stack*/
t_stack	*new_node(int value);
void	append_node(t_stack **stack, t_stack *new);
t_stack	*init_stack(int argc, char **argv);

#endif