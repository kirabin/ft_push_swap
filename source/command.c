#include "includes.h"

bool	is_valid_command(char *command)
{
	if (!_strcmp(command, "sa"))
		return (true);
	if (!_strcmp(command, "sb"))
		return (true);
	if (!_strcmp(command, "ss"))
		return (true);
	if (!_strcmp(command, "pa"))
		return (true);
	if (!_strcmp(command, "pb"))
		return (true);
	if (!_strcmp(command, "ra"))
		return (true);
	if (!_strcmp(command, "rb"))
		return (true);
	if (!_strcmp(command, "rr"))
		return (true);
	if (!_strcmp(command, "rra"))
		return (true);
	if (!_strcmp(command, "rrb"))
		return (true);
	if (!_strcmp(command, "rrr"))
		return (true);
	return (0);
}
