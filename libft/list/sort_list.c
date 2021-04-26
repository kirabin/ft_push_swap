#include "libft.h"

void	sort_list(t_list **list, int (*compare)(t_list *, t_list *))
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
