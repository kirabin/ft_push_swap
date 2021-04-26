#include "libft.h"

void	put_uint_hex(unsigned int n, int is_upper)
{
	if (0 <= n && n <= 9)
		put_char(n + '0');
	else if (10 <= n && n <= 15)
	{
		if (is_upper)
			put_char(n - 10 + 'A');
		else
			put_char(n - 10 + 'a');
	}
	else
	{
		put_uint_hex(n / 16, is_upper);
		put_uint_hex(n % 16, is_upper);
	}
}

void	put_uint_hex_fd(unsigned int n, int is_upper, int fd)
{
	if (0 <= n && n <= 9)
		put_char_fd(n + '0', fd);
	else if (10 <= n && n <= 15)
	{
		if (is_upper)
			put_char_fd(n - 10 + 'A', fd);
		else
			put_char_fd(n - 10 + 'a', fd);
	}
	else
	{
		put_uint_hex_fd(n / 16, is_upper, fd);
		put_uint_hex_fd(n % 16, is_upper, fd);
	}
}
