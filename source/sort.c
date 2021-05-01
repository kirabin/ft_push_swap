#include "includes.h"



void	quick_sort_ab(t_all *all)
{
	int		average;

	// all->sorted = copy_list();
	put_list_forward(all->sorted, put_void_int, " ", "\n");
	sort_list(&all->sorted, list_compare_int_more);
	put_list_forward(all->sorted, put_void_int, " ", "\n");
	average = find_avg(all->stack_a);
	return ;
}
