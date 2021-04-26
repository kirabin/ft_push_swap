#include "libft.h"

char	ft_tolower(char c)
{
	if ('A' <= c && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}
