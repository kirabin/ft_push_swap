#include "libft.h"

t_color	new_color(unsigned char a, unsigned char r, unsigned char g,
			unsigned char b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}
