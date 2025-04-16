/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:56:31 by mrosset           #+#    #+#             */
/*   Updated: 2025/04/16 15:29:41 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if (*src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	temp->next = *dest;
	if (*dest != NULL)
		(*dest)->prev = temp;
	*dest = temp;
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}

/*
** stack->value  allow to access to the value pointed by stack
**void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_b == NULL) // if the stack is empty, we do nothing
		return ; // and quite
	temp = *stack_b; // we take the first element of b
	*stack_b = (*stack_b)->next; // we move this element from stack b
	to stack a. the stack b become the next element
	if (*stack_b != NULL) // if the stack isn't empty
		(*stack_b)->prev = NULL; // we update the ptr prev to the next
		element
	temp->next = *stack_a; // the new element of the stack a point
	the old first element to the stack a
	if (*stack_a != NULL) // if teh stack a isn't empty
		(*stack_a)->prev = temp; // we update the ptr prev of the
		fisrt element of a
	*stack_a = temp; // the new element become the fisrt element of
	the stack a
	ft_printf("pa\n"); // display the opration
}*/
