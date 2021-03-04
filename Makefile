# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 10:53:38 by dmilan            #+#    #+#              #
#    Updated: 2021/03/04 11:52:09 by dmilan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS				= -Wall -Wextra #-Werror
NAME_CHECKER		= checker
NAME_PUSH_SWAP		= push_swap
LIBFT				= libft/libft.a
SRC					=
OBJ					= $(SRC:.c=.o)
HEADER				= includes.h

$(LIBFT): libft/**/*.c
	make -C libft/

$(NAME_PUSH_SWAP): $(SRC) $(HEADER) push_swap.c
	gcc $(FLAGS) -o push_swap push_swap.c

$(NAME_CHECKER): $(SRC) $(HEADER) checker.c
	gcc $(FLAGS) -o checker checker.c

all: $(LIBFT) $(NAME_CHECKER) $(NAME_PUSH_SWAP)

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
