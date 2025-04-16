/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:24:37 by mrosset           #+#    #+#             */
/*   Updated: 2025/04/16 14:33:59 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	int	value;
	int	index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

#endif