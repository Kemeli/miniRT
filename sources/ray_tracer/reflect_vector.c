#include <minirt.h>

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	t_tuple	multiply;
	t_tuple	reflect;

	multiply = multiply_tuple_by_scalar(normal, 2 * dot(in, normal));
	reflect = subtract(in, multiply);
	free(multiply);
	return (reflect);
}
