#include "includes.h"

void	ft_put_stacks_ab(t_list *a, t_list *b)
{
	put_string("---\n");
	put_string("a| ");
	put_list_forward(a, put_void_int_space);
	put_string("\n");
	put_string("b| ");
	put_list_forward(b, put_void_int_space);
	put_string("---\n");
}

// {
// 	t_list	*start_a;
// 	t_list	*start_b;
// 	int		width;

// 	width = 12;
// 	start_a = a;
// 	start_b = b;
// 	put_string("a           b\n\n");
// 	while (a || b)
// 	{
// 		if (a && a != start_a)
// 		{
// 			put_int(*(int *)a->content);
// 			put_char_times(' ', width - int_len(*(int *)a->content));
// 			a = a->next;
// 		}
// 		else
// 		{
// 			put_char_times(' ', width);
// 		}
// 		if (b && b != start_b)
// 		{
// 			put_int(*(int *)b->content);
// 			put_char_times(' ', width - int_len(*(int *)b->content));
// 			b = b->next;
// 		}
// 		else
// 		{
// 			put_char_times(' ', width);
// 		}
// 		put_char('\n');
// 		if (a == start_a && !b)
// 			break ;
// 		if (b == start_b && !a)
// 			break ;
// 	}
// 	put_string("_________________________\n");
// }

// TODO: verbose flag for put_stacks
void	execute_commands(t_all *all)
{
	t_queue	*command;

	command = all->commands;
	while (command)
	{
		execute_command(command->content, &all->stack_a, &all->stack_b);
		command = command->next;
	}
}

void	execute_command(char *command, t_list **a, t_list **b)
{
	if (!_strcmp(command, "sa") || !_strcmp(command, "ss"))
		execute_swap(a);
	if (!_strcmp(command, "sb") || !_strcmp(command, "ss"))
		execute_swap(b);
	if (!_strcmp(command, "pa"))
		execute_push(b, a);
	if (!_strcmp(command, "pb"))
		execute_push(a, b);
	if (!_strcmp(command, "ra") || !_strcmp(command, "rr"))
		execute_rotation(a);
	if (!_strcmp(command, "rb") || !_strcmp(command, "rr"))
		execute_rotation(b);
	if (!_strcmp(command, "rra") || !_strcmp(command, "rrr"))
		execute_reverse_rotation(a);
	if (!_strcmp(command, "rrb") || !_strcmp(command, "rrr"))
		execute_reverse_rotation(b);
}
