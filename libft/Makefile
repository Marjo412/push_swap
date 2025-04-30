# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 10:28:06 by mrosset           #+#    #+#              #
#    Updated: 2025/04/30 12:15:13 by mrosset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a #nom du programme a créer

CC = cc #définit le compilateur à utiliser
CFLAGS = -Wall -Wextra -Werror -I. #flags utilisé pour compiler, I. ajoute le repertoire .h

SRCS = ft_atoi.c \ #liste des sources à compiler
	   ft_atol.c \
	   ft_bzero.c \
	   ft_calloc.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_itoa.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_putchar_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_putstr_fd.c \
	   ft_split.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_striteri.c \
	   ft_strjoin.c \
	   ft_strlcat.c \
	   ft_strlcpy.c \
	   ft_strlen.c \
	   ft_strmapi.c \
	   ft_strncmp.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_strtrim.c \
	   ft_substr.c \
	   ft_tolower.c \
	   ft_toupper.c \

OBJS = $(SRCS:.c=.o) #liste des objets à générer à partir des sources

$(NAME): $(OBJS) #la cible dépend des objets à créer, peut le faire seulement si objs sont dispos 
	ar rcs $(NAME) $(OBJS)

%.o: %.c libft.h #règle de compilation pour chaque fichier .o, dépendant de son .c correspondant et de libft.h.
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) #cible à exécuter en lancant 'make'

clean: #supprime tous les fichiers .o en lancant 'clean'
	rm -rf $(OBJS)

fclean: clean #supprime les objets dans 'clean' ainsi que l'archive, pour recompiler depuis 0.
	rm -rf $(NAME)

re: fclean all #Exécute fclean puis all, soit une recompilation complète.

.PHONY: all clean fclean re #Indique que les cibles ne correspondent pas à des fichiers mais à des actions.
#Cela empêche les conflits si des fichiers portant ces noms existent.

#ar : utilitaire pour créer et manipuler les archives
#rcs : 'r' remplace les fichiers dans l'archive, 'c'crée l'archive, 's' ajoute l'index.
#$(CC) $(CFLAGS) -c $< -o $@ : Compilation de chaque fichier .c en un fichier objet .o
#$< : Le premier prérequis (ici, le fichier .c correspondant)
#$@ : Le nom de la cible (.o), correspondant à % dans le modèle