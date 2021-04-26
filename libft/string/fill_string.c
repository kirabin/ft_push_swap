#include "libft.h"

char	*fill_string(char *s, char c)
{
	char	*temp;

	temp = s;
	while (temp && *temp)
		*temp = c;
	return (s);
}
