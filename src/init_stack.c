/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:26:11 by mrosset           #+#    #+#             */
/*   Updated: 2025/04/16 17:43:12 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	append_node(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*node;
	int		i;
	int		value;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		node = new_node(value);
		if (!node)
			return (NULL);
		append_node(&stack, node);
		i++;
	}
	return (stack);
}
