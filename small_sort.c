/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:31:31 by marvin            #+#    #+#             */
/*   Updated: 2025/04/30 18:36:28 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
	else
		radix_sort(a, b);
}

void	sort_2(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		swap_a(*a);
}

void	sort_3(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		swap_a(*a);
	else if (first > second && second > third)
	{
		swap_a(*a);
		reverse_rotate_a(a);
	}
	else if (first > second && second < third && first > third)
		rotate_a(a);
	else if (first < second && second > third && first < third)
	{
		swap_a(*a);
		rotate_a(a);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(a);
}

void	sort_4(t_stack **a, t_stack **b)
{
	int	min_node;

	min_node = get_min_node(*a);
	while ((*a)->value != min_node)
		rotate_a(a);
	push_b(a, b);
	sort_3(a);
	push_a(a, b);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	min_node;

	min_node = get_min_node(*a);
	while ((*a)->value != min_node)
		rotate_a(a);
	push_b(a, b);
	min_node = get_min_node(*a);
	while ((*a)->value != min_node)
		rotate_a(a);
	push_b(a, b);
	sort_3(a);
	push_a(a, b);
	push_a(a, b);
}
