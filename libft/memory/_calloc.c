#include "libft.h"

void	*_calloc(size_t count, size_t size)
{
	unsigned char	*res;
	size_t			i;

	i = 0;
	res = malloc(size * count);
	if (!res)
		return (NULL);
	while (i < size * count)
		res[i++] = 0;
	return (res);
}
