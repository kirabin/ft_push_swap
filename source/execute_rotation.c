#include "includes.h"

// Rotate stack (first element becomes last one)
void	execute_rotation(t_list **list)
{
	t_list	*temp;
	t_list	*first;

	if (!*list || !(*list)->next)
		return ;
	temp = *list;
	*list = (*list)->next;
	first = temp;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = first;
	first->next = NULL;
}
