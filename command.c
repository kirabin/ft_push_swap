#include "includes.h"

bool	is_valid_command(char *command)
{
	if (!_strcmp(command, "sa"))
		return (1);
	if (!_strcmp(command, "sb"))
		return (1);
	if (!_strcmp(command, "ss"))
		return (1);
	if (!_strcmp(command, "pa"))
		return (1);
	if (!_strcmp(command, "pb"))
		return (1);
	if (!_strcmp(command, "ra"))
		return (1);
	if (!_strcmp(command, "rb"))
		return (1);
	if (!_strcmp(command, "rr"))
		return (1);
	if (!_strcmp(command, "rra"))
		return (1);
	if (!_strcmp(command, "rrb"))
		return (1);
	if (!_strcmp(command, "rrr"))
		return (1);
	return (0);
}
