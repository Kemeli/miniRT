#include <minirt.h>

t_tuple	cross(t_tuple a, t_tuple b)
{
	float	x;
	float	y;
	float	z;
	t_tuple	result;

	x = a[1] * b[2] - a[2] * b[1];
	y = a[2] * b[0] - a[0] * b[2];
	z = a[0] * b[1] - a[1] * b[0];
	result = vector(x, y, z);
	return (result);
}
