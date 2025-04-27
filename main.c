/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:44:59 by mrosset           #+#    #+#             */
/*   Updated: 2025/04/27 14:57:33 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_and_init(int argc, char **argv, t_stack **a)
{
	int	i;
	int	nums;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			exit_error(a, NULL);
		nums = ft_atoi(argv[i]);
		append_node(a, new_node(nums));
		i++;
	}
	if (has_duplicate(*a))
		exit_error(a, NULL);
	if (is_sorted(*a))
	{
		free_stack(*a);
		exit(0);
	}
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

/*check_and_init : check if the args are valid, if */