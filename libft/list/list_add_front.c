#include "libft.h"

void	list_add_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	if (*lst)
		(*lst)->previous = new;
	*lst = new;
}
