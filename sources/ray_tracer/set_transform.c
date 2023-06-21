#include <minirt.h>

void	set_transform(t_sphere *sphere, float **translation)
{
	float	**transform;

	transform = sphere->transform;
	sphere->transform = multiply_matrix(transform, translation);
	free_matrix(transform);
}
