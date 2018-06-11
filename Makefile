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

NAME 			= libfts.a

NAME_TEST 		= test

ASFLAGS 		= nasm -f macho64

CC 				= cc -Wall -Wextra -Werror

SRC 			=	src/ft_bzero.s \
					src/ft_strcat.s \
					src/ft_isalpha.s \
					src/ft_isdigit.s \
					src/ft_isalnum.s \
					src/ft_isascii.s \
					src/ft_isprint.s \
					src/ft_toupper.s \
					src/ft_tolower.s \
					src/ft_puts.s 	\
					src/ft_strlen.s \
					src/ft_memset.s \
					src/ft_memcpy.s \
					src/ft_strdup.s \
					src/ft_cat.s 	\
					src/bonus/ft_putchar.s \
					src/bonus/ft_putchar_fd.s \
					src/bonus/ft_puts_fd.s \
					src/bonus/ft_isupper.s \
					src/bonus/ft_islower.s \
					src/bonus/ft_isspace.s \


OBJ 			= $(SRC:%.s=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)


%.o:%.s
	$(ASFLAGS) $<

clean:
	@/bin/rm -f $(OBJ)
	@echo "rm .o"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo  "rm $(NAME)"

re: fclean all

test: $(OBJ) main.c
	$(CC) main.c $(NAME) -o $(NAME_TEST)

clean_test:
	/bin/rm -f $(NAME_TEST)

.PHONY: clean fclean re test clean_test