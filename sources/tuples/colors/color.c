#include <minirt.h>

t_tuple	color(float r, float g, float b)
{
	t_tuple	c;

	c = tuple(r, g, b, 0);
	return (c);
}
