/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:56:35 by mrosset           #+#    #+#             */
/*   Updated: 2025/04/16 16:43:58 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	before_last = last->prev;
	before_last->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}

void	reverse_rotate_a(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	reverse_rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}

/*void	reverse_rotate(t_stack **stack)
{
	t_stack	*last; // the last element of the stack
	t_stack	*before_last; // the last before element

	if (!stack || !*stack || !(*stack)->next) // check if the ptr to the
	stack is NULL, if the stack is empty, if there is only 1 element
		return ; // if it's true juste retrun;
	last = *stack;
	while (last->next) // we loop until it's NULL
		last = last->next; // last got the last element of the stack
	before_last = last->prev; // we get the last before element
	before_last->next = NULL; // we transform it in a new end by
	putting next in NULL
	last->next = *stack; // point to the old first element
	last->prev = NULL; // become the new first
	(*stack)->prev = last; // the old first point back to the new one
	*stack = last; // stack is update to point to the new fist (last)
}*/