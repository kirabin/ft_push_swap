#include "includes.h"

void	execute_command(char *command, t_list **a, t_list **b)
{
	if (!_strcmp(command, "sa") || !_strcmp(command, "ss"))
		execute_swap(a);
	if (!_strcmp(command, "sb") || !_strcmp(command, "ss"))
		execute_swap(b);
	if (!_strcmp(command, "pa"))
		execute_push(b, a);
	if (!_strcmp(command, "pb"))
		execute_push(a, b);
	if (!_strcmp(command, "ra") || !_strcmp(command, "rr"))
		execute_rotation(a);
	if (!_strcmp(command, "rb") || !_strcmp(command, "rr"))
		execute_rotation(b);
	if (!_strcmp(command, "rra") || !_strcmp(command, "rrr"))
		execute_reverse_rotation(a);
	if (!_strcmp(command, "rrb") || !_strcmp(command, "rrr"))
		execute_reverse_rotation(b);
}
