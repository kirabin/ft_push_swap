#include "includes.h"

int	find_mini(t_list *list)
{
	int		min;
	int		min_i;
	int		i;
	t_list	*start;

	min = 0;
	i = 0;
	min_i = 0;
	if (list)
	{
		min = *(int *)list->content;
		start = list;
		while (list)
		{
			if (*(int *)list->content < min)
			{
				min = *(int *)list->content;
				min_i = i;
			}
			list = list->next;
			if (list == start)
				break ;
			i++;
		}
	}
	return (min_i);
}

void	bubble_sort(t_all *all)
{
	int		min;
	int		min_i;
	int		size;

	while (all->stack_a)
	{
		min = find_min(all->stack_a);
		min_i = find_mini(all->stack_a);
		size = list_size(all->stack_a);
		if (min_i < size - min_i)
		{
			while (*(int *)all->stack_a->content != min)
			{
				execute_rotation(&all->stack_a);
				push_queue(&all->commands, new_queue(_strdup("ra")));
			}
		}
		else
		{
			while (*(int *)all->stack_a->content != min)
			{
				execute_reverse_rotation(&all->stack_a);
				push_queue(&all->commands, new_queue(_strdup("rra")));
			}
		}
		execute_push(&all->stack_a, &all->stack_b);
		push_queue(&all->commands, new_queue(_strdup("pb")));
	}
	while (all->stack_b)
	{
		execute_push(&all->stack_b, &all->stack_a);
		push_queue(&all->commands, new_queue(_strdup("pa")));
	}
}
