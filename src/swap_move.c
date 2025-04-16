/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:56:39 by mrosset           #+#    #+#             */
/*   Updated: 2025/04/16 14:19:06 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
}

void	swap_a(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_stack *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

/*void swap(t_stack *stack)//take a ptr and will modifie the stack
{
	int	temp; // will serve to store a value during the change

	if (!stack || !stack->next) // if the stach is empty,
	there is only one element and we can't do a swap
		return ; // so we quite the function
	temp = stack->value; // we save the value
	stack->value = stack->next->value; // we replace the value of the fisrt
	element with the second element
	stack->next->value = temp; // we end the change by put in the second
	element int the fisrt one that we saved.
}*/