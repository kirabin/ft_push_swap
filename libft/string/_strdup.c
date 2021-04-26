#include "libft.h"

char	*_strdup(const char *s1)
{
	char	*res;
	int		i;

	i = -1;
	if (!s1)
		return (NULL);
	res = malloc(sizeof(char) * (_strlen((char *)s1) + 1));
	if (res)
	{
		while (s1[++i])
			res[i] = s1[i];
		res[i] = '\0';
	}
	return (res);
}

char	*_strndup(const char *s1, int n)
{
	char	*res;
	int		i;
	int		len;

	i = -1;
	if (!s1)
		return (NULL);
	len = _strlen((char *)s1);
	res = malloc(sizeof(char) * (len + 1));
	if (res)
	{
		while (s1[++i] && i < n)
			res[i] = s1[i];
		res[i] = '\0';
	}
	return (res);
}
