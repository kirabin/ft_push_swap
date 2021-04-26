#include "libft.h"

bool	is_digit(char c)
{
	if ('0' <= c && c <= '9')
		return (true);
	return (false);
}
