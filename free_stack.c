/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:52:46 by mrosset           #+#    #+#             */
/*   Updated: 2025/05/04 11:58:35 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	free_input(char **input, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(input[i++]);
	free(input);
}

/***free_input : permet de liberer la memoire d'un tableau d'une string cree
	avec split;*/