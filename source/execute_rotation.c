#include "includes.h"

// Rotate stack (first element becomes last one)
void	execute_rotation(t_list **list)
{
	t_list	*start;

	if (list)
	{
		start = *list;
		if (start->next)
		{
			*list = start->next;
		}
	}
}
