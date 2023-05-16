#include <minirt.h>

float	magnitude(t_tuple v)
{
	float	x_squared;
	float	y_squared;
	float	z_squared;
	float	w_squared;
	float	result;

	x_squared = pow(v[0], 2);
	y_squared = pow(v[1], 2);
	z_squared = pow(v[2], 2);
	w_squared = pow(v[3], 2);
	result = sqrt(x_squared + y_squared + z_squared + w_squared);
	return (result);
}
