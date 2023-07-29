#include <minirt.h>

void	set_transform(t_sphere **sphere, t_matrix translation)
{
	t_matrix	transform;

	transform = (*sphere)->transform;
	(*sphere)->transform = multiply_matrix(transform, translation);
	free_matrix(transform);
}
