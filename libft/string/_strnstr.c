#include "libft.h"

/*
**		Locate a substring in a string
*/
char	*_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[j] && j < len)
	{
		if (haystack[j] == needle[i])
		{
			if (needle[++i] == '\0')
				return ((char *)haystack + j - i + 1);
		}
		else
		{
			j -= i;
			i = 0;
		}
		j++;
	}
	return (NULL);
}
