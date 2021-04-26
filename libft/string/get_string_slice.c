#include "libft.h"

char	*get_string_slice(char *s, int start, int stop)
{
	char	*res;
	int		len;
	int		i;

	if (!s || start >= stop || start < 0)
		return (NULL);
	i = 0;
	len = stop - start;
	if (_strlen(s) < start || _strlen(s) < len || _strlen(s) < stop)
		return (NULL);
	res = malloc(len + 1);
	if (res)
	{
		while (s[start + i] && start + i < stop)
		{
			res[i] = s[start + i];
			i++;
		}
		res[len] = '\0';
	}
	return (res);
}
