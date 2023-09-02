#include <minirt.h>

t_tuple	color(double r, double g, double b)
{
	t_tuple	c;

	c = tuple(r, g, b, 0);
	return (c);
}
