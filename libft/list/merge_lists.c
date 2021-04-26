#include "libft.h"

// TODO: rewrite merge_lists
void	merge_lists(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*node;

	node = *begin_list1;
	while (node->next)
		node = node->next;
	node->next = begin_list2;
}
