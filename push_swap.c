#include "includes.h"

int	find_min(t_list *list)
{
	int		min;

	if (list)
		min = *(int *)list->content;
	while (list)
	{
		if (*(int *)list->content < min)
			min = *(int *)list->content;
		list = list->next;
	}
	return (min);
}

int	find_max(t_list *list)
{
	int		max;

	if (list)
		max = *(int *)list->content;
	while (list)
	{
		if (*(int *)list->content > max)
			max = *(int *)list->content;
		list = list->next;
	}
	return (max);
}

void	bubble_sort_ab(t_all *all)
{
	int		max;

	while (all->stack_a)
	{
		max = find_max(all->stack_a);
		while (*(int *)all->stack_a->content != max)
		{
			execute_rotation(&all->stack_a);
			list_add_back(&all->commands, new_list(_strdup("ra")));
		}
		execute_push(&all->stack_a, &all->stack_b);
		list_add_back(&all->commands, new_list(_strdup("pb")));
	}
	while (all->stack_b)
	{
		execute_push(&all->stack_b, &all->stack_a);
		list_add_back(&all->commands, new_list(_strdup("pa")));
	}
}

void	stack_sort_ab(t_all *all)
{
	int		temp;

	while(all->stack_a)
	{
		temp = *(int *)all->stack_a->content;
		execute_rotation(&all->stack_a);
		list_add_back(&all->commands, new_list(_strdup("ra")));
		ft_put_stacks_ab(all->stack_a, all->stack_b);
		while(all->stack_b && *(int *)all->stack_b->content > temp)
		{
			execute_push(&all->stack_b, &all->stack_a);
			list_add_back(&all->commands, new_list(_strdup("pb")));
			ft_put_stacks_ab(all->stack_a, all->stack_b);
		}
		execute_reverse_rotation(&all->stack_a);
		list_add_back(&all->commands, new_list(_strdup("rra")));
		ft_put_stacks_ab(all->stack_a, all->stack_b);
		execute_push(&all->stack_a, &all->stack_b);
		list_add_back(&all->commands, new_list(_strdup("pb")));
		ft_put_stacks_ab(all->stack_a, all->stack_b);
	}
	while (all->stack_b)
	{
		execute_push(&all->stack_b, &all->stack_a);
		list_add_back(&all->commands, new_list(_strdup("pa")));
		ft_put_stacks_ab(all->stack_a, all->stack_b);
	}
}

void	print_commands(t_list *commands)
{
	while (commands)
	{
		put_two_strings(commands->content, "\n");
		commands = commands->next;
	}
}

int	main(int argc, char **argv)
{
	t_all	*all;

	if (argc >= 2)
	{
		all = init_all();
		all->stack_a = argv_to_stack_a(argv + 1);
		if (all->stack_a)
		{
			bubble_sort_ab(all);
			print_commands(all->commands);
		}
		free_all(all);
	}
	else
		put_string("Error: Not enough arguments!\n");
	return (0);
}
