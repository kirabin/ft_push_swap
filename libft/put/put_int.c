#include "libft.h"

void	put_int(int n)
{
	if (0 <= n && n <= 9)
		put_char(n + '0');
	else if (n >= 10)
	{
		put_int(n / 10);
		put_int(n % 10);
	}
	else
	{
		put_char('-');
		if (n / 10)
			put_int(-(n / 10));
		put_int(-(n % 10));
	}
}

void	put_int_fd(int n, int fd)
{
	if (0 <= n && n <= 9)
		put_char_fd(n + '0', fd);
	else if (n >= 10)
	{
		put_int_fd(n / 10, fd);
		put_int_fd(n % 10, fd);
	}
	else
	{
		put_char_fd('-', fd);
		if (n / 10)
			put_int_fd(-(n / 10), fd);
		put_int_fd(-(n % 10), fd);
	}
}
