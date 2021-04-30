#include "includes.h"

// void	sort_thre(t_che *che)
// {
// 	while (!sort_che(che->la, ascending))
// 	{
// 		if (che->la->norm == 2)
// 		{
// 			RA;
// 			rotate_ab(&che->la);
// 		}
// 		else if (che->la->norm < che->la->next->norm)
// 		{
// 			RRA;
// 			revrot_ab(&che->la);
// 		}
// 		else if (che->la->norm > che->la->next->norm)
// 		{
// 			SA;
// 			swap_ab(che->la);
// 		}
// 	}
// }

// void	rra3(t_che *che)
// {
// 	while (!sort_che(che->la, ascending))
// 	{
// 		RRA;
// 		revrot_ab(&che->la);
// 	}
// }

// int		find_5(t_che *che, int len, int smal)
// {
// 	t_stack *tmp;
// 	int		count;

// 	count = 0;
// 	tmp = che->la;
// 	while (tmp)
// 	{
// 		if (tmp->norm <= smal)
// 		{
// 			if (count >= len / 2)
// 				return (0);
// 		}
// 		count++;
// 		tmp = tmp->next;
// 	}
// 	return (1);
// }

// void	sort_5(t_che *che)
// {
// 	while (ft_lstlen(che->la) > 3)
// 	{
// 		if (find_next(che, ft_lstlen(che->la), 1) == 0)
// 		{
// 			while (che->la->norm > 1)
// 			{
// 				RA;
// 				rotate_ab(&che->la);
// 			}
// 			PB;
// 			push_ab(&che->la, &che->lb);
// 		}
// 		else
// 		{
// 			while (che->la->norm > 1)
// 			{
// 				RRA;
// 				revrot_ab(&che->la);
// 			}
// 			PB;
// 			push_ab(&che->la, &che->lb);
// 		}
// 	}
// 	sort_thre(che);
// 	back2a(che);
// }

// void	sort(t_che *che, int llen)
// {
// 	if (ft_lstlen(che->la) == 5)
// 	{
// 		sort_5(che);
// 		exit(0);
// 	}
// 	while (ft_lstlen(che->la) >= 5)
// 	{
// 		get_chunk(che, llen - 1);
// 		llen = ft_lstlen(che->la);
// 	}
// 	while (che->la->norm != 3)
// 	{
// 		RA;
// 		rotate_ab(&che->la);
// 	}
// 	PB;
// 	push_ab(&che->la, &che->lb);
// 	sort_thre(che);
// 	back2a(che);
// 	rra3(che);
// }

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

void	bubble_pebble_sort_ab(t_all *all)
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
			bubble_pebble_sort_ab(all);
			print_commands(all->commands);
		}
		free_all(all);
	}
	else
		put_string("Error: Not enough arguments!\n");
	return (0);
}
