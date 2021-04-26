#include "libft.h"

bool	is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t' || c == '\r' || c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}
