#include <minirt.h>

void	set_transform(t_object **obj, t_matrix translation)
{
	t_matrix	transform;

	transform = (*obj)->transform;
	(*obj)->transform = multiply_matrix(transform, translation);
	free_matrix(transform);
}
