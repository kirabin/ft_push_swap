#include "libft.h"

char	*string_join_char(char *s, char c)
{
	char	*new_string;
	int		s_len;
	int		i;

	i = 0;
	s_len = _strlen(s);
	new_string = malloc(s_len + 1 + 1);
	new_string[s_len] = c;
	new_string[s_len + 1] = '\0';
	while (s && s[i])
	{
		new_string[i] = s[i];
		i++;
	}
	free(s);
	return (new_string);
}
