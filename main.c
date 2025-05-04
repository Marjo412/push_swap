/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:44:59 by mrosset           #+#    #+#             */
/*   Updated: 2025/05/04 11:51:24 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input_validity(char **input, int count, t_stack **a)
{
	int		i;
	int		nums;
	t_stack	*node;

	i = 0;
	while (i < count)
	{
		if (!is_valid_number(input[i]))
			exit_error(a, NULL);
		nums = ft_atoi(input[i]);
		node = new_node(nums);
		if (!node)
			exit_error(a, NULL);
		append_node(a, node);
		i++;
	}
}

void	check_and_init(int argc, char **argv, t_stack **a)
{
	char	**input;
	int		count;
	int		nf;

	count = 0;
	nf = 0;
	input = input_init(argc, argv, &count, &nf);
	check_input_validity(input, count, a);
	if (has_duplicate(*a))
		exit_error(a, NULL);
	if (is_sorted(*a))
	{
		free_stack(*a);
		exit(0);
	}
	if (nf)
		free_input(input, count);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	check_and_init(argc, argv, &a);
	size = stack_size(a);
	if (size == 2)
		sort_2(&a);
	else if (size == 3)
		sort_3(&a);
	else if (size == 4)
		sort_4(&a, &b);
	else if (size == 5)
		sort_5(&a, &b);
	else
		sort_stack(&a, &b);
	free_stack(a);
	return (0);
}

/*
**check_input_validity : verifie si c'est un nb valid, le converti
	en int, alloue la memoire avec new_node, ajoute de noeud avec
	append_node a la stack, si necessaire quitte le programme
**check_and_init : recupere la liste des entrees avec input_init
	appelle check_init_validity pour construire la stack, vefifie
	les doublons, verifie si la stack est deja triee, libere la
	memroir si split est utilise avec le flag nf (need free).
*/