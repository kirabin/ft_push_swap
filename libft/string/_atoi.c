#include "libft.h"

// TODO: test for -1
int	_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') * 2 - 1;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		if (res * sign > 2147483647)
			return (-1);
		if (res * sign < -2147483648)
			return (0);
	}
	return (res * sign);
}

long long	_atoi_long_long(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '+') * 2 - 1;
	while (*str && is_digit(*str))
		res = res * 10 + (*str++ - '0') * sign;
	return (res);
}
