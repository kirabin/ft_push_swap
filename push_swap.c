#include "includes.h"

void	bubble_sort_ab(t_all *all)
{
	int		min;

	while (all->stack_a)
	{
		min = find_min(all->stack_a);
		while (*(int *)all->stack_a->content != min)
		{
			execute_rotation(&all->stack_a);
			push_queue(&all->commands, new_queue(_strdup("ra")));
		}
		execute_push(&all->stack_a, &all->stack_b);
		all->stack_a->flag = true;
		push_queue(&all->commands, new_queue(_strdup("pb")));
	}
	while (all->stack_b)
	{
		execute_push(&all->stack_b, &all->stack_a);
		push_queue(&all->commands, new_queue(_strdup("pa")));
	}
}

void	stack_sort_ab(t_all *all)
{
	int		temp;

	while (all->stack_a)
	{
		temp = *(int *)all->stack_a->content;
		execute_rotation(&all->stack_a);
		push_queue(&all->commands, new_queue(_strdup("ra")));
		while (all->stack_b && *(int *)all->stack_b->content > temp)
		{
			execute_push(&all->stack_b, &all->stack_a);
			all->stack_a->flag = true;
			push_queue(&all->commands, new_queue(_strdup("pb")));
		}
		execute_reverse_rotation(&all->stack_a);
		push_queue(&all->commands, new_queue(_strdup("rra")));
		execute_push(&all->stack_a, &all->stack_b);
		all->stack_a->flag = true;
		push_queue(&all->commands, new_queue(_strdup("pb")));
	}
	while (all->stack_b)
	{
		execute_push(&all->stack_b, &all->stack_a);
		push_queue(&all->commands, new_queue(_strdup("pa")));
	}
}

static void print_optimized_commands(t_queue *queue)
{
	// TODO: ra ra rb rb -> rr rr
	while (queue && queue->next)
	{
		if (_strcmp(queue->content, "ra") == 0 && _strcmp(queue->next->content, "rb") == 0)
		{
			put_two_strings("rr", "\n");
			queue = queue->next;
		}
		else if (_strcmp(queue->content, "rb") == 0 && _strcmp(queue->next->content, "ra") == 0)
		{
			put_two_strings("rr", "\n");
			queue = queue->next;
		}
		else if (_strcmp(queue->content, "rra") == 0 && _strcmp(queue->next->content, "rrb") == 0)
		{
			put_two_strings("rrr", "\n");
			queue = queue->next;
		}
		else if (_strcmp(queue->content, "rrb") == 0 && _strcmp(queue->next->content, "rra") == 0)
		{
			put_two_strings("rrr", "\n");
			queue = queue->next;
		}
		else if (_strcmp(queue->content, "pa") == 0 && _strcmp(queue->next->content, "pb") == 0)
			queue = queue->next;
		else if (_strcmp(queue->content, "pb") == 0 && _strcmp(queue->next->content, "pa") == 0)
			queue = queue->next;
		else
			put_two_strings(queue->content, "\n");
		queue = queue->next;
	}
	if (queue)
		put_two_strings(queue->content, "\n");
}

int	main(int argc, char **argv)
{
	t_all	*all;

	if (argc >= 2)
	{
		all = init_all();
		all->stack_a = argv_to_stack(argv + 1);
		if (all->stack_a)
		{
			all->sorted = argv_to_stack(argv + 1);
			// bubble_sort_ab(all);
			quick_sort_ab(all);
			print_optimized_commands(all->commands);
			// put_queue(optimized, put_void_string, "\n", "");
			// ft_put_stacks_ab(all->stack_a, all->stack_b);
		}
		free_all(all);
	}
	else
		put_string("Error: Not enough arguments!\n");
	return (0);
}
