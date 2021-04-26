#include "libft.h"

int	_strcmp(const char *s1, const char *s2)
{
	unsigned int	index;
	int				comp_value;

	index = 0;
	if (!s1 || !s2)
		return (s1 == s2);
	while (s1[index] || s2[index])
	{
		comp_value = (unsigned char)s1[index] - (unsigned char)s2[index];
		if (comp_value)
			return (comp_value);
		index++;
	}
	return (0);
}

int	_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	index;
	int				comp_value;

	index = 0;
	if (!s1)
		return (0 - *s2);
	while ((s1[index] || s2[index]) && index < n)
	{
		comp_value = (unsigned char)s1[index] - (unsigned char)s2[index];
		if (comp_value)
			return (comp_value);
		index++;
	}
	return (0);
}
