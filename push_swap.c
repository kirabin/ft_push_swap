#include "includes.h"

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

void	queue_del_next(t_queue *queue)
{
	t_queue		*node;

	if (queue)
	{
		if (queue->next)
		{
			node = queue->next;
			queue->next = node->next;
			delete_queue(node, free);
		}
	}
}

static void print_optimized_commands(t_queue *queue)
{
	t_queue	*start;
	int		i;

	// TODO: ra ra rb rb -> rr rr
	i = 0;
	start = queue;
	while (queue && queue->next)
	{
		if ((_strcmp(queue->content, "ra") == 0 && _strcmp(queue->next->content, "rb") == 0)
			|| (_strcmp(queue->content, "rb") == 0 && _strcmp(queue->next->content, "ra") == 0))
		{
			queue = queue->previous;
			queue_del_next(queue);
			free(queue->next->content);
			queue->next->content = _strdup("rr");
		}
		else if ((_strcmp(queue->content, "rra") == 0 && _strcmp(queue->next->content, "rrb") == 0)
					|| (_strcmp(queue->content, "rrb") == 0 && _strcmp(queue->next->content, "rra") == 0))
		{
			queue = queue->previous;
			queue_del_next(queue);
			free(queue->next->content);
			queue->next->content = _strdup("rrr");
		}
		else if ((_strcmp(queue->content, "pa") == 0 && _strcmp(queue->next->content, "pb") == 0)
					|| (_strcmp(queue->content, "pb") == 0 && _strcmp(queue->next->content, "pa") == 0)
					|| (_strcmp(queue->content, "ra") == 0 && _strcmp(queue->next->content, "rra") == 0)
					|| (_strcmp(queue->content, "rb") == 0 && _strcmp(queue->next->content, "rrb") == 0)
					|| (_strcmp(queue->content, "rra") == 0 && _strcmp(queue->next->content, "ra") == 0)
					|| (_strcmp(queue->content, "rrb") == 0 && _strcmp(queue->next->content, "rb") == 0))
		{
			queue = queue->previous;
			queue_del_next(queue);
			queue_del_next(queue);
		}
		else
			queue = queue->next;
	}
	put_queue(start, put_void_string, "\n", "");
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
			if (list_size(all->stack_a) == 3)
				sort_three(all);
			else if (list_size(all->stack_a) == 5)
				sort_five(all);
			else
			{
				// quick_sort(all);
				bubble_sort(all);
			}
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
