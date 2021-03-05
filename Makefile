# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 10:53:38 by dmilan            #+#    #+#              #
#    Updated: 2021/03/05 15:38:08 by macbookpro       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS				= -Wall -Wextra -g #-Werror
NAME_CHECKER		= checker
NAME_PUSH_SWAP		= push_swap
LIBFT				= libft/libft.a
SRC					= execute/execute_push.c \
					  execute/execute_rotation.c \
					  execute/execute_reverse_rotation.c \
					  execute/execute_swap.c
OBJ					= $(SRC:.c=.o)
HEADER				= includes.h

all: $(LIBFT) $(NAME_CHECKER) $(NAME_PUSH_SWAP)

$(LIBFT): libft/**/*.c
	make -C libft/

$(NAME_PUSH_SWAP): $(SRC) $(HEADER) push_swap.c
	gcc $(FLAGS) -o push_swap push_swap.c $(SRC) libft/libft.a -I.

$(NAME_CHECKER): $(SRC) $(HEADER) checker.c
	gcc $(FLAGS) -o checker checker.c $(SRC) libft/libft.a -I.


clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME_CHECKER) $(NAME_PUSH_SWAP)

re: fclean all

test:
	# ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
	# echo "pb\npb\npa" | ./checker 1 2 3 4
	# echo "pb\nsa\nsb" | ./checker 1 2 3 4
	# echo "ra\nra\npb" | ./checker 1 2 3 3
	echo "rra\nrra\npb" | ./checker 1 2 3 4


