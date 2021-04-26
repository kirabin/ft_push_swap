#include "libft.h"

char	*_itoa(int n)
{
	char	*res;
	int		i;
	int		len;
	int		sign;

	sign = 1;
	len = int_len(n);
	i = len - 1;
	res = malloc(len + 1);
	if (res)
	{
		if (n < 0)
			sign = -1;
		while (i >= 0)
		{
			res[i--] = (n % 10) * sign + '0';
			n /= 10;
		}
		if (sign == -1)
			res[0] = '-';
		res[len] = '\0';
	}
	return (res);
}
