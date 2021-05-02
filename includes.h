#ifndef INCLUDES_H
# define INCLUDES_H

# include "libft/libft.h"

typedef struct s_all
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*sorted;
	t_list	*next_sort;
	t_queue	*commands;
	bool	flag_verbose;
}	t_all;

t_list		*argv_to_stack(char **argv);
void		ft_put_stacks_ab(t_list *a, t_list *b);

t_all		*init_all(void);
void		free_all(t_all *all);

bool		is_valid_command(char *command);

void		execute_commands(t_all *all);
void		execute_command(char *command, t_list **a, t_list **b);
void		execute_push(t_list **from, t_list **to);
void		execute_reverse_rotation(t_list **list);
void		execute_rotation(t_list **list);
void		execute_swap(t_list **list);

void		quick_sort(t_all *all);
void		bubble_sort(t_all *all);
void		sort_three(t_all *all);
void		sort_five(t_all *all);

int			find_min(t_list *list);
int			find_max(t_list *list);
int			find_avg(t_list *list);

#endif
