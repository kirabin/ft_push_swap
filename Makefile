FLAGS				=	-Wall -Wextra -Werror -g
NAME_CHECKER		=	checker
NAME_PUSH_SWAP		=	push_swap
LIBFT				=	libft/libft.a
SRC					=	source/execute_push.c \
						source/execute_rotation.c \
						source/execute_reverse_rotation.c \
						source/execute_swap.c \
						source/execute_command.c \
						source/command.c \
						source/all.c

OBJ					=	$(SRC:.c=.o)
HEADER				=	includes.h

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
	ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l

	bash ../tester.sh ./push_swap 100 10
