#include "libft.h"

void	put_two_strings(char *s1, char *s2)
{
	put_string(s1);
	put_string(s2);
}

void	put_two_strings_fd(char *s1, char *s2, int fd)
{
	put_string_fd(s1, fd);
	put_string_fd(s2, fd);
}
