#include "libft.h"

bool	is_alpha(char c)
{
	if ('a' <= c && c <= 'z')
		return (true);
	if ('A' <= c && c <= 'Z')
		return (true);
	return (false);
}
