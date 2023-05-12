#include <minirt.h>

t_tuple	tuple(float x, float y, float z, float w)
{
	t_tuple	tuple;

	tuple = malloc(sizeof(float) * 4);
	if (!tuple)
		return (NULL);
	tuple[0] = x;
	tuple[1] = y;
	tuple[2] = z;
	tuple[3] = w;
	return (tuple);
}

t_tuple vector(float x, float y, float z)
{
	t_tuple	vector;

	vector = tuple(x, y, z, 0);
	return (vector);
}

t_tuple point(float x, float y, float z)
{
	t_tuple	point;

	point = tuple(x, y, z, 1);
	return (point);
}
