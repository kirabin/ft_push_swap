#include "libft.h"

double	point_len(t_point point)
{
	return (sqrt(point.x * point.x + point.y * point.y));
}
