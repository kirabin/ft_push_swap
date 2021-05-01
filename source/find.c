#include "includes.h"

int	find_min(t_list *list)
{
	int		min;
	t_list	*start;

	min = 0;
	if (list)
	{
		min = *(int *)list->content;
		start = list;
		while (list)
		{
			if (*(int *)list->content < min)
				min = *(int *)list->content;
			list = list->next;
			if (list == start)
				break ;
		}
	}
	return (min);
}

int	find_max(t_list *list)
{
	t_list	*start;
	int		max;

	max = 0;
	if (list)
	{
		max = *(int *)list->content;
		start = list;
		while (list)
		{
			if (*(int *)list->content > max)
				max = *(int *)list->content;
			list = list->next;
			if (list == start)
				break ;
		}
	}
	return (max);
}

int	find_avg(t_list *list)
{
	t_list		*start;
	long		sum;
	int			i;

	sum = 0;
	i = 0;
	start = list;
	while (list)
	{
		sum += *(int *)list->content;
		i++;
		list = list->next;
		if (list == start)
			break ;
	}
	if (i > 0)
		return (sum / i);
	return (0);
}
