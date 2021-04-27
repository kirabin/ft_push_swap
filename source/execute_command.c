#include "includes.h"

void	ft_put_stacks_ab(t_list *a, t_list *b)
{
	put_string("___\n");
	while (a || b)
	{
		if (a)
		{
			put_int(*(int *)a->content);
			a = a->next;
		}
		else
			putchar(' ');
		putchar(' ');
		if (b)
		{
			put_int(*(int *)b->content);
			b = b->next;
		}
		else
			putchar(' ');
		putchar('\n');
	}
	put_string("___\n");
	put_string("a b\n");
}

// TODO: verbose flag for put_stacks
void	execute_commands(t_all *all)
{
	t_list	*command;

	command = all->commands;
	while (command)
	{
		execute_command(command->content, &all->stack_a, &all->stack_b);
		ft_put_stacks_ab(all->stack_a, all->stack_b);
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
