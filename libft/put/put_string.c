#include "libft.h"

void	put_string(char *s)
{
	while (s && *s)
		put_char(*s++);
}

void	put_string_fd(char *s, int fd)
{
	while (s && *s)
		put_char_fd(*s++, fd);
}

void	put_string_n(char *s, int n)
{
	int		i;

	i = 0;
	while (s && s[i] && i < n)
		put_char(s[i++]);
}

void	put_string_n_fd(char *s, int n, int fd)
{
	int		i;

	i = 0;
	while (s && s[i] && i < n)
		put_char_fd(s[i++], fd);
}
