#include <minirt.h>

t_tuple	multiply_colors(t_tuple c1, t_tuple c2)
{
	float	r;
	float	g;
	float	b;
	t_tuple	result;

	r = c1[0] * c2[0];
	g = c1[1] * c2[1];
	b = c1[2] * c2[2];
	result = color (r, g, b);
	return (result);
}
