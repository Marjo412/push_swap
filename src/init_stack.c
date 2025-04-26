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

/***new_node : create a new node for the stack, allocate the memory and
 check, stock the value, initialize the index with a default value (it will
 be change later), the node is alone for now so there is nothing prev and
 next and it return the ptr to the node.
** append_node : attach a new node at the end of the stack, fisrt check
 if the the ptr to the stack  and the new node aren't NULL (stop the 
 function if there is true), if the stack is empty the new node beacome the
 fisrt of the stack, else we loop until we found the last (next == NULL)
 and we link the last to the new node. the last (next) point to the new and
 the new point to the prev.
** init_stack : build the stack while looping through the args, initialize
the stack empty and the index at 1 (we don't want the progr name), we loop
until i is smaller than args. Each value must be an int so we convert, we
create a new node with this value (in new_node there is malloc) and check
the memory allocation and we add the node at the end of the stack and pass
to the next, when all the args are passed the function return the stack.
*/