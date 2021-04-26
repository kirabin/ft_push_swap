#include "libft.h"

bool	is_number(char *str)
{
	if (!str)
		return (false);
	while (*str)
	{
		if (!is_digit(*str))
			return (false);
		str++;
	}
	return (true);
}
