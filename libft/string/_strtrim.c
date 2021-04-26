#include "libft.h"

char	*_strtrim(char *s1, char *set)
{
	unsigned int	start;
	unsigned int	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && find_char(set, s1[start]))
		start++;
	end = start;
	while (s1[end])
		end++;
	while (end && find_char(set, s1[end]))
		end--;
	if (end < start)
		return (_strdup(""));
	return (get_string_slice(s1, start, end - start + 1));
}
