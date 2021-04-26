#include "libft.h"

char	*skip_char(char *s, char c)
{
	if (!s)
		return (s);
	while (*s && *s == c)
		s++;
	return (s);
}
