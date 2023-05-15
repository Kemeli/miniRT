#include <minirt.h>

t_tuple	negative(t_tuple v)
{
	t_tuple	result;

	result = vector(v[0] * -1, v[1] * -1, v[2] * -1);
	return (result);
}
