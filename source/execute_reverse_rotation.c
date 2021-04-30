#include "includes.h"

// Reverse rotate stack (last element becomes first one)
void	execute_reverse_rotation(t_list **list)
{
	t_list	*start;

	if (list)
	{
		start = *list;
		if (start->previous)
		{
			*list = start->previous;
		}
	}
}
