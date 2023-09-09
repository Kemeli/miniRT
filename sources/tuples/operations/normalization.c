#include <minirt.h>

t_tuple	normalize(t_tuple v)
{
	double	x;
	double	y;
	double	z;
	double	w;
	double	length;

	length = magnitude(v);
	x = v[0] / length;
	y = v[1] / length;
	z = v[2] / length;
	w = v[3] / length;
	return (tuple(x, y, z, w));
}
