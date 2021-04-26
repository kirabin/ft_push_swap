#include "libft.h"

void	put_list(t_list *list, void (*put)(void *content))
{
	if (!list)
		put_string("list is empty");
	else
	{
		while (list)
		{
			put(list->content);
			list = list->next;
		}
	}
	put_string("\n");
}
