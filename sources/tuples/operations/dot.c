#include <minirt.h>

double	dot(t_tuple v, t_tuple w)
{
	return (v[0] * w[0] + v[1] * w[1] + v[2] * w[2] + v[3] * w[3]);
}
