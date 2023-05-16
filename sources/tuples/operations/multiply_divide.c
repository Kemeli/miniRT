#include <minirt.h>

t_tuple	scalar_multiplication(t_tuple tuple_a, float times_to_multiply)
{
	t_tuple	result;
	float	x;
	float	y;
	float	z;
	float	w;

	x = tuple_a[0] * times_to_multiply;
	y = tuple_a[1] * times_to_multiply;
	z = tuple_a[2] * times_to_multiply;
	w = tuple_a[3] * times_to_multiply;
	result = tuple(x, y, z, w);
	return (result);
}

t_tuple	scalar_division(t_tuple tuple_a, float times_to_divide)
{
	t_tuple	result;
	float	x;
	float	y;
	float	z;
	float	w;

	x = tuple_a[0] / times_to_divide;
	y = tuple_a[1] / times_to_divide;
	z = tuple_a[2] / times_to_divide;
	w = tuple_a[3] / times_to_divide;
	result = tuple(x, y, z, w);
	return (result);
}
