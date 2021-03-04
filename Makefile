# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 10:53:38 by dmilan            #+#    #+#              #
#    Updated: 2021/03/04 12:17:21 by dmilan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS				= -Wall -Wextra -g #-Werror
NAME_CHECKER		= checker
NAME_PUSH_SWAP		= push_swap
LIBFT				= libft/libft.a
SRC					=
OBJ					= $(SRC:.c=.o)
HEADER				= includes.h

all: $(LIBFT) $(NAME_CHECKER) $(NAME_PUSH_SWAP)

$(LIBFT): libft/**/*.c
	make -C libft/

$(NAME_PUSH_SWAP): $(SRC) $(HEADER) push_swap.c
	gcc $(FLAGS) -o push_swap push_swap.c libft/libft.a -I.

$(NAME_CHECKER): $(SRC) $(HEADER) checker.c
	gcc $(FLAGS) -o checker checker.c libft/libft.a -I.


clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME_CHECKER) $(NAME_PUSH_SWAP)

re: fclean all

test:
	# ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
	#
