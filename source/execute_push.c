#include "includes.h"

// TODO: list_remove_index()
void	execute_push(t_list **from, t_list **to)
{
	t_list	*node;
	t_list	*last;

	if (from && to)
	{
		if (*from)
		{
			node = *from;
			if (*from)
			{
				if (list_size(*from) == 2)
				{
					*from = node->next;
					(*from)->next = NULL;
					(*from)->previous = NULL;
				}
				else if ((*from)->previous)
				{
					last = (*from)->previous;
					*from = node->next;
					(*from)->previous = last;
					last->next = *from;
				}
				else
					*from = NULL;
			}
			else
				*from = NULL;
			node->next = NULL;
			node->previous = NULL;
			list_add_front(to, node);
		}
	}
}
