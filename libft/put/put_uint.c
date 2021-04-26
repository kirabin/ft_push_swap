#include "libft.h"

void	put_uint(unsigned int n)
{
	if (0 <= n && n <= 9)
		put_char(n + '0');
	else
	{
		put_uint(n / 10);
		put_uint(n % 10);
	}
}

void	put_uint_fd(unsigned int n, int fd)
{
	if (0 <= n && n <= 9)
		put_char_fd(n + '0', fd);
	else
	{
		put_uint_fd(n / 10, fd);
		put_uint_fd(n % 10, fd);
	}
}
