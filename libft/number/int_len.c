#include "libft.h"

int	intlen(int n)
{
	int	len;

	len = !(n > 0);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}
