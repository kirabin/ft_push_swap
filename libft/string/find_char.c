#include "libft.h"

char	*find_char(const char *s, int c)
{
	int	i;

	i = 0;
	while (true)
	{
		if (s[i] == c)
			return ((char *)s + i);
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return (NULL);
}
