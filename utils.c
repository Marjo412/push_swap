/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:44:47 by marvin            #+#    #+#             */
/*   Updated: 2025/04/27 09:22:08 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack	*get_min_node(t_stack *stack)
{
	t_stack	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (stack->index < min ->index)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

/***stack_size: define the size of the stack (ft_strlen)
**get_min_node : find the node with the smaller index in the stack, utile in
 small_sort.c, if the stack is empty, return NULL. We start with the fisrt
 element (min = stack), we loop in the stack, if we find a node with smaller
 index and we pass to the next index. when the stack is finish it return 
 the smallest found (min)*/