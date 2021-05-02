#include "includes.h"

static void	first_iteration(t_all *all)
{
	int		average;
	int		i;
	int		size;

	i = 0;
	size = list_size(all->stack_a);
	average = find_avg(all->stack_a);
	while (all->stack_a && i < size)
	{
		if (*(int *)all->stack_a->content <= average)
		{
			all->stack_a->flag = true;
			execute_push(&all->stack_a, &all->stack_b);
			push_queue(&all->commands, new_queue(_strdup("pb")));
		}
		else
		{
			execute_rotation(&all->stack_a);
			push_queue(&all->commands, new_queue(_strdup("ra")));
		}
		ft_put_stacks_ab(all->stack_a, all->stack_b);
		i++;
	}
}

static void	second_iteration(t_all *all)
{
	int		average;
	int		i;
	int		size;

	i = 0;
	size = list_size(all->stack_b);
	average = find_avg(all->stack_b);
	while (all->stack_b && i < size)
	{
		while (all->stack_a && all->next_sort != all->sorted && *(int *)all->stack_a->content == *(int *)all->next_sort->content)
		{
			execute_rotation(&all->stack_a);
			push_queue(&all->commands, new_queue(_strdup("ra")));
			all->next_sort = all->next_sort->next;
		}
		while (all->stack_a && all->next_sort != all->sorted && *(int *)all->stack_a->next->content == *(int *)all->next_sort->content)
		{
			execute_swap(&all->stack_a);
			push_queue(&all->commands, new_queue(_strdup("sa")));
			execute_rotation(&all->stack_a);
			push_queue(&all->commands, new_queue(_strdup("ra")));
			all->next_sort = all->next_sort->next;
		}
		if (*(int *)all->stack_b->content >= average)
		{
			execute_push(&all->stack_b, &all->stack_a);
			push_queue(&all->commands, new_queue(_strdup("pa")));
			while (all->stack_a && all->next_sort != all->sorted && *(int *)all->stack_a->content == *(int *)all->next_sort->content)
			{
				execute_rotation(&all->stack_a);
				push_queue(&all->commands, new_queue(_strdup("ra")));
				all->next_sort = all->next_sort->next;
			}
			while (all->stack_a && all->next_sort != all->sorted && *(int *)all->stack_a->next->content == *(int *)all->next_sort->content)
			{
				execute_swap(&all->stack_a);
				push_queue(&all->commands, new_queue(_strdup("sa")));
				execute_rotation(&all->stack_a);
				push_queue(&all->commands, new_queue(_strdup("ra")));
				all->next_sort = all->next_sort->next;
			}
		}
		else
		{
			execute_rotation(&all->stack_b);
			push_queue(&all->commands, new_queue(_strdup("rb")));
			while (all->stack_b && *(int *)all->stack_b->content == *(int *)all->next_sort->content)
			{
				execute_push(&all->stack_b, &all->stack_a);
				push_queue(&all->commands, new_queue(_strdup("pa")));
				execute_rotation(&all->stack_a);
				push_queue(&all->commands, new_queue(_strdup("ra")));
				all->next_sort = all->next_sort->next;
				i++;
			}
			while (all->stack_b && all->stack_b->next && *(int *)all->stack_b->next->content == *(int *)all->next_sort->content)
			{
				execute_swap(&all->stack_b);
				push_queue(&all->commands, new_queue(_strdup("sb")));
				execute_push(&all->stack_b, &all->stack_a);
				push_queue(&all->commands, new_queue(_strdup("pa")));
				execute_rotation(&all->stack_a);
				push_queue(&all->commands, new_queue(_strdup("ra")));
				all->next_sort = all->next_sort->next;
				i++;
			}
		}
		ft_put_stacks_ab(all->stack_a, all->stack_b);
		i++;
	}
	while (all->stack_b)
	{
		execute_push(&all->stack_b, &all->stack_a);
		push_queue(&all->commands, new_queue(_strdup("pa")));
		if (*(int *)all->stack_a->content == *(int *)all->next_sort->content)
		{
			execute_rotation(&all->stack_a);
			push_queue(&all->commands, new_queue(_strdup("ra")));
			all->next_sort = all->next_sort->next;
		}
		ft_put_stacks_ab(all->stack_a, all->stack_b);
	}
}

static int	find_avg_fill_sorted_first(t_all *all)
{
	int		sum;
	int		i;
	t_list	*copy;

	sum = 0;
	i = 0;
	copy = all->stack_a;
	while (*(int *)copy->content != *(int *)all->sorted->content)
	{
		sum += *(int *)copy->content;
		i++;
		copy = copy->next;
		if (copy == all->stack_a)
			break ;
	}
	if (i > 0)
		return (sum / i);
	return (0);
}

static void	third_iteration(t_all *all)
{
	int		average;
	int		i;
	int		flaged;

	i = 0;
	flaged = 0;
	average = find_avg_fill_sorted_first(all);
	while (*(int *)all->stack_a->content != *(int *)all->sorted->content
			&& all->stack_a->flag != 0)
	{
		flaged = 1;
		if (*(int *)all->stack_a->content <= average + 1)
		{
			all->stack_a->flag = true;
			execute_push(&all->stack_a, &all->stack_b);
			push_queue(&all->commands, new_queue(_strdup("pb")));
		}
		else
		{
			execute_rotation(&all->stack_a);
			push_queue(&all->commands, new_queue(_strdup("ra")));
			i++;
		}
		ft_put_stacks_ab(all->stack_a, all->stack_b);
	}
	if (flaged == 0)
	{
		while (*(int *)all->stack_a->content != *(int *)all->sorted->content)
	{
		flaged = 1;
		if (*(int *)all->stack_a->content <= average + 1)
		{
			all->stack_a->flag = true;
			execute_push(&all->stack_a, &all->stack_b);
			push_queue(&all->commands, new_queue(_strdup("pb")));
		}
		else
		{
			execute_rotation(&all->stack_a);
			push_queue(&all->commands, new_queue(_strdup("ra")));
			i++;
		}
		ft_put_stacks_ab(all->stack_a, all->stack_b);
	}
	}
	while (i > 0)
	{
		execute_reverse_rotation(&all->stack_a);
		push_queue(&all->commands, new_queue(_strdup("rra")));
		i--;
		ft_put_stacks_ab(all->stack_a, all->stack_b);
	}

}

void	quick_sort(t_all *all)
{
	int		i;

	i = 0;
	sort_list(&all->sorted, list_compare_int_more);
	all->next_sort = all->sorted;
	first_iteration(all);
	// while (!(all->stack_b == NULL && is_list_sorted(all->stack_a, list_compare_int_more)))
	// while (all->next_sort)
	while (!(all->stack_b == NULL && all->next_sort == all->sorted))
	{
		second_iteration(all);
		third_iteration(all);
		i++;
	}
	return ;
}
