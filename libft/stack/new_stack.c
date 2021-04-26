#include "libft.h"

t_stack	*new_stack(void *content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = 0;
	return (node);
}
