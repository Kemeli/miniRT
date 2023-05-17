#include <minirt.h>

t_tuple	normalize(t_tuple v)
{
	float	x;
	float	y;
	float	z;
	float	w;
	t_tuple	result;

	x = v[0] / magnitude(v);
	y = v[1] / magnitude(v);
	z = v[2] / magnitude(v);
	w = v[3] / magnitude(v);
	result = tuple(x, y, z, w);
	return (result);
}
