#include "libft.h"

bool	is_name(const char *str)
{
	if (*str == '_' || is_alpha(*str))
	{
		str++;
		while (*str)
		{
			if (*str != '_' && !(is_alpha(*str) || is_digit(*str)))
				return (false);
			str++;
		}
		return (true);
	}
	return (false);
}
