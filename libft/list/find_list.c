#include "libft.h"

t_list	*find_list(t_list *begin_list, void *data_ref,
	bool (*compare)(void *, void *))
{
	while (begin_list)
	{
		if (compare(begin_list->content, data_ref))
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (NULL);
}
