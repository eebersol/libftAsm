# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/30 14:18:45 by eebersol          #+#    #+#              #
#    Updated: 2015/03/30 14:18:49 by eebersol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftasm.a

NAME_TEST = test

AS = nasm

ASFLAGS = -f macho64

CC = cc -Wall -Wextra -Werror

LIBS = -L ./ -lfts

SRC =	ft_bzero.s \
		ft_strcat.s \
		ft_isalpha.s \
		ft_isdigit.s \
		ft_isalnum.s \
		ft_isascii.s \
		ft_isprint.s \
		ft_toupper.s \
		ft_tolower.s \
		ft_puts.s 	\
		ft_strlen.s \
		ft_memset.s \

OBJ = $(SRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

test: $(OBJ) main.c
	$(CC) main.c $(NAME) -o $(NAME_TEST)

clean_test:
	/bin/rm -f $(NAME_TEST)

.PHONY: clean fclean re test clean_test