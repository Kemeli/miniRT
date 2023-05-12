#include <minirt.h>

t_tuple	subtract(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result = tuple(a[0] - b[0], a[1] - b[1], a[2] - b[2], fabs(a[3] - b[3]));
	return (result);
}
