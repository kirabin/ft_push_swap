#include "libft.h"

void	clear_list(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*temp;

	node = *lst;
	if (!del || !*lst)
		return ;
	while (node)
	{
		del(node->content);
		temp = node;
		node = node->next;
		free(temp);
	}
	*lst = NULL;
}
