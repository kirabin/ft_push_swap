#include "includes.h"

void	sort_three(t_all *all)
{
	int		a;
	int		b;
	int		c;

	a = *(int *)all->stack_a->content;
	b = *(int *)all->stack_a->next->content;
	c = *(int *)all->stack_a->next->next->content;
}
