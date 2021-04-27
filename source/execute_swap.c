#include "includes.h"

// Swap first two elements on top of the stack "list"
void	execute_swap(t_list **list)
{
	t_list	*first;
	t_list	*second;

	if (!*list || !(*list)->next)
		return ;
	first = *list;
	second = first->next;
	swap_list_content(first, second);
}
