#include "libft.h"

void	reverse_list(t_list **begin_list)
{
	t_list	*previous;
	t_list	*current;
	t_list	*next;

	current = *begin_list;
	previous = NULL;
	while (current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*begin_list = previous;
}
