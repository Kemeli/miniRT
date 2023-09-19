#include <minirt.h>

void	set_transform(t_object *o, t_matrix transform)
{
	o->inverse = inverse(transform);
	o->transpose_inverse = transpose_matrix(o->inverse);
}
