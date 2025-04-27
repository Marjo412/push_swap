/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 08:28:27 by marvin            #+#    #+#             */
/*   Updated: 2025/04/27 14:49:35 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!isdigit(str[i]))
		return (0);
	while (isdigit(str[i]))
		i++;
	while (isspace(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	has_duplicate(t_stack *stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	exit_error(t_stack **a, t_stack **b)
{
	if (a)
		free_stack(*a);
	if (b)
		free_stack(*b);
	ft_printf("Error\n");
	exit(1);
}
/***is_valid_number : pass the sign, we check only the num, if there is no num
 in the stack return 0, we exclue all char exept 0 to 9.
**has_duplicate : check if there is no dup num, current is a ptr to loop in
 the stack, it is the current num and compare each num in the stack. checker 
 is a ptr who loop in the nexts nums and compare it with all each nums to see
 if there is a dup. if 2 values are equal, we quite the programme, if there is
 no dup we pass to the next num, if checker has passed all the stack without
 found a dup current became the next element. the function return 0 if there is
 no dup.
**is_sorted : check if the stack is already sorted, first check if the stack
 isn't empty and the next num exist, if there is at least 2 nums the programme
 can continue and when there is the last num the loop stops. the function
 compare the num to the next numand if the next num is biggert its mean that
 the stack isn't sorted so return 0. if the next value isn't bigger the
 function continue with the next value. if the stack is sorted return 1 so
 the programme can stop because the stack is already sorted.
**exit_error : free a, free b if they exist, print the error message and
 quite the programme.*/