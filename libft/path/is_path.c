#include "libft.h"

bool	is_path(char *string)
{
	if (is_absolute_path(string)
		|| is_relative_path(string))
		return (true);
	return (false);
}

bool	is_absolute_path(char *string)
{
	if (string[0] == '/')
		return (true);
	return (false);
}

bool	is_relative_path(char *string)
{
	if (!string)
		return (false);
	if (string[0] != '/' && find_char(string, '/'))
		return (true);
	return (false);
}
