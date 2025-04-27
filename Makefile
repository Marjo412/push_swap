# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 11:07:39 by mrosset           #+#    #+#              #
#    Updated: 2025/04/27 09:37:40 by mrosset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I include

LIBFT_DIRECTORY = libft
LIBFT_ARCHIVE = $(LIBFT_DIRECTORY)/libft.a

FT_PRINTF_DIRECTORY = ft_printf
FT_PRINTF_ARCHIVE = $(FT_PRINTF_DIRECTORY)/libftprintf.a

SRCS = 

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIRECTORY) $(FT_PRINTF_DIRECTORY) -o $(NAME)

$(LIBFT_ARCHIVE):
	$(MAKE) -C $(LIBFT_DIRECTORY)

$(FT_PRINTF_ARCHIVE):
	$(MAKE) -C $(FT_PRINTF_DIRECTORY)


clean:
		rm -rf $(OBJS)
		make clean -C $(LIBFT_DIRECTORY)
		make clean -C $(FT_PRINTF_DIRECTORY)
		
		
fclean: clean
		rm -rf $(NAME)
		make fclean -C $(LIBFT_DIRECTORY)
		make fclean -C $(FT_PRINTF_DIRECTORY)
				

re: fclean all

.PHONY: all clean fclean re