#include "libft.h"

t_point	point_add(t_point a, t_point b)
{
	t_point	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	return (res);
}
