#include "libft.h"

char	*string_join(char const *s1, char const *s2)
{
	int		len;
	char	*res;
	int		i;

	i = 0;
	len = _strlen((char *)s1) + _strlen((char *)s2);
	res = _calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	return (res);
}

char	*string_join_three(char const *s1, char const *s2, char const *s3)
{
	int		len;
	char	*res;
	int		i;

	i = 0;
	len = _strlen((char *)s1) + _strlen((char *)s2) + _strlen((char *)s3);
	res = _calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	while (*s3)
		res[i++] = *s3++;
	return (res);
}
