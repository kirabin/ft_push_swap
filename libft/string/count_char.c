#include "libft.h"

int	count_char(const char *s, char c)
{
	int	count;

	count = 0;
	while (s && *s)
		if (*s++ == c)
			count++;
	return (count);
}
