################################################################################
#                                                                              #
#                                VARIABLES                                     #
#                                                                              #
################################################################################
RED			=	\033[31m
GREEN		=	\033[32m
ORANGE		=	\033[93m
NO_COLOR	=	\033[0m

NAME		=	libft.a
HEADER		=	libft.h
FLAGS		=	-Wall -Wextra -Werror -g

SRC_STR		=	_strlen _atoi _itoa _strdup _strcmp _strnstr _strtrim \
				fill_string find_char count_char skip_char is_name \
				string_join string_join_free split_string get_next_line \
				string_join_char

SRC_CHR		=	is_alpha is_digit is_space to_lower to_upper

SRC_NUM		=	_abs int_max int_min int_len swap_int \
				is_long_long is_number is_integer

SRC_PUT		=	put_char put_cpp put_int put_string put_two_strings put_uint \
				put_uint_hex

SRC_PATH	=	is_path get_file_name_from_path

SRC_LST		=	clear_list delete_list find_list list_add_back list_add_front \
				list_get_last list_size merge_lists new_list put_list \
				reverse_list sort_list swap_list_content

SRC_MEM		=	_calloc

SRC_FREE	=	free_cpp

SRC_COLOR	=	new_color

SRC_POINT	=	point_add point_len point_new point_rotate

SRC			=	$(patsubst %, string/%.c, $(SRC_STR)) \
				$(patsubst %, memory/%.c, $(SRC_MEM)) \
				$(patsubst %, char/%.c, $(SRC_CHR)) \
				$(patsubst %, put/%.c, $(SRC_PUT)) \
				$(patsubst %, number/%.c, $(SRC_NUM)) \
				$(patsubst %, free/%.c, $(SRC_FREE)) \
				$(patsubst %, color/%.c, $(SRC_COLOR)) \
				$(patsubst %, point/%.c, $(SRC_POINT)) \
				$(patsubst %, path/%.c, $(SRC_PATH)) \
				$(patsubst %, list/%.c, $(SRC_LST))

OBJ			=	$(SRC:.c=.o)

################################################################################
#                                                                              #
#                                RULES                                         #
#                                                                              #
################################################################################
.PHONY: all clean fclean re

all: $(NAME)

shout_assemble:
	@echo "$(GREEN)Assembling libft$(NO_COLOR)"

shout_clean:
	@echo "$(RED)Cleaning libft$(NO_COLOR)"

shout_test:
	@echo "$(ORANGE)Testing$(NO_COLOR)"

%.o: %.c $(HEADER)
	gcc -c $(FLAGS) $< -o $@ -I.

$(NAME): shout_assemble $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean: shout_clean
	rm -f **/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette
