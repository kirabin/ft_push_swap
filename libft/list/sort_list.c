#include "libft.h"

void	sort_list(t_list **list, bool (*compare)(void *, void *))
{
	t_list		*a;
	t_list		*b;

	a = *list;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (compare(a, b))
				swap_list_content(a, b);
			b = b->next;
		}
		a = a->next;
	}
}

// Compare (int)a > (int)b
bool	list_compare_int_more(void *a, void *b)
{
	if (*(int *)a > *(int *)b)
		return (true);
	return (false);
}

// Compare (int)a == (int)b
bool	list_compare_int_equal(void *a, void *b)
{
	if (*(int *)a == *(int *)b)
		return (true);
	return (false);
}

bool	is_list_sorted(t_list *list, bool (*compare)(void *, void *))
{
	if (!list || !list->next)
		return (true);
	while (list->next)
	{
		if (compare(list->content, list->next->content))
			return (false);
		list = list->next;
	}
	return (true);
}
