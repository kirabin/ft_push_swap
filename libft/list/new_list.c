#include "libft.h"

t_list	*new_list(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

t_list	*new_list_int(int a)
{
	t_list	*node;
	int		*content;

	content = malloc(sizeof(int));
	if (!content)
		return (NULL);
	*content = a;
	node = malloc(sizeof(t_list));
	if (!node)
	{
		free(content);
		return (NULL);
	}
	node->content = content;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}
