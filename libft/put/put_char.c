#include "libft.h"

void	put_char(char c)
{
	write(1, &c, 1);
}

void	put_char_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	put_char_times(char c, int times)
{
	int	i;

	i = 0;
	while (i < times)
	{
		write(1, &c, 1);
		i++;
	}
}
