#include "libft.h"

t_list	*find_list(t_list *begin_list, void *data_ref, int (*cmp)())
{
	while (begin_list)
	{
		if ((*cmp)(begin_list->content, data_ref))
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (NULL);
}
