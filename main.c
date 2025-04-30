/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:44:59 by mrosset           #+#    #+#             */
/*   Updated: 2025/04/30 17:39:04 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_input(char **input, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(input[i++]);
	free(input);
}

char	**input_init(int argc,char **argv, int *count, int *nf)
{
	char **input;
	
	if (argc == 2)
	{
		input = ft_split(argv[1], ' ', count);
		*nf = 1;
	}
	else
	{
		input = &argv[1];
		*count = argc - 1;
	}
	return (input);
}

void	check_and_init(int argc, char **argv, t_stack **a)
{
	int	i;
	int	nums;
	int	count;
	char **input;
	int		nf;

	count = 0;
	nf = 0;
	input = input_init(argc, argv, &count, &nf);
	i = 0;
	while (i < count)
	{
		if (!is_valid_number(input[i]))
			exit_error(a, NULL);
		nums = ft_atoi(input[i]);
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

/*check_and_init : check if the args are valid, if */