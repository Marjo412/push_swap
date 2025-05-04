/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:56:43 by mrosset           #+#    #+#             */
/*   Updated: 2025/05/04 10:41:23 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	rotate_a(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

/*void rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next) // 3 conditions pour verifier
	qu'il y ait bien des elements dans la pile : si le ptr vers stack est
	NULL = la pile n'existe pas, si la stack est vide elle pointe 
	vers NULL = on fait rien, si la pile a un seul element il n'y a pas de
	suivant = on ne peut pas faire de rotation.
		return ; // si une des conditions est vraie, return sans rien faire
	first = *stack; // pointe sur le 1er element de la pile
	last = *stack; // point aussi le 1er au debut
	while (last->next) // parcourt la pile pour trouver le dernier element
		last = last->next; // avance au prochain element jusqu'au dernier
	*stack = first->next; met a jour la tete de la pile vers l'element
	suivant de first
	(*stack)->prev = NULL; // on met a jour prev de ce nouvel element, le
	nouveau 1er pour qu'il pointe vers NULL
	first->next = NULL; // On détache le premier élément de la pile en le
	déconnectant de son prochain élément.
	first->prev = last; // On fait pointer le premier élément vers last,
	ce qui signifie qu'il devient le dernier élément de la pile
	last->next = first; // on relie le dernier élément(ancien dernier 
	élément) au premier élément pour le faire revenir en fin de pile.
}
ra (rotate a) : Décale d’une position vers le haut tous les élements de la
	pile a. Le premier élément devient le dernier.
rb (rotate b) : Décale d’une position vers le haut tous les élements de la
	pile b. Le premier élément devient le dernier.
rr : ra et rb en même temps*/