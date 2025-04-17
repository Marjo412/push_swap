/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:30:58 by marvin            #+#    #+#             */
/*   Updated: 2025/04/17 17:30:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap."

void	radix_sort(t_stack **a, t_stack **b)
{
	int size;
	int max_bits;
	int bit;

	assign_index(*a);
	size = stack_size(*a);
	max_bits = get_max_bits(*a);
	bit = 0;
	while (bit < max_bits)
	{
		sort_by_bit(a, b, bit, size);
		bit++;
	}
}

void	sort_by_bit(t_stack **a, t_stack **b, int bit, int size)
{
	int i;
	int num;

	i = 0;
	while (i < size)
	{
		num = (*a)->index;
		if (((num >> bit) & 1) == 0)
			push_b(a, b);
		else
			rotate_a(a);
		i++;
	}
	while (*b)
		push_a(a, b);
}

int	stack_size(t_stack *stack)
{
	int count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int	get_max_bits(t_stack *stack)
{
	int max;
	int bits;

	max = stack_size(stack);
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	assign_index(t_stack *stack)
{
	t_stack *ptr1;
	t_stack *ptr2;
	int index;

	ptr1 = stack;
	while (ptr1)
	{
		index = 0;
		ptr2 = stack;
		while (ptr2)
		{
			if (ptr2->value < ptr1->value)
				index++;
			ptr2 = ptr2->next;
		}
		ptr1->index = index;
		ptr1 = ptr1->next;
	}
}

/*
1*void assign_index: va attribuer un index à chaque element en fonction
de sa valeur relative, en commencant par le 1er puis parcourt la pile, 
si le suiavnt est plus petit on incremente, puis on attribue l'index à ptr1

2*int stack_size: compte combien il y a d'éléments dans la pile et return
le compte final

3*int get_max_bits: calcule le nb de bits pour le plus grand des index,
compare chaque elements jusqu'a max et return le nb de bits

4*void sort_by_bit: fait un passage de tri en fonction d'un bit donné dans
le index, commence à position 0 pour regarde chaque élément de stack_a et 
compare si c'est 0 (push dans b) ou 1(rotate a), a la fin remet tout dans
a depuis b.

5*void radix_sort: fonction principale de tri, coordonne toutes les étapes
précédents et permet l'appel aux autres fonctions pour un tri bien effectué
*/