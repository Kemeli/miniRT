#include <minirt.h>

static void	update_temp(float ***t);

t_tuple	normal_at(t_sphere *sphere, t_tuple world_point)
{
	t_tuple	normal;
	t_tuple	obj_point;
	t_tuple	obj_normal;
	t_tuple	world_normal;
	float	**temp;

	temp = inverse(sphere->transform);
	obj_point = multiply_matrix_with_tuple(temp, world_point);
	obj_normal = subtract(obj_point, sphere->center);
	update_temp(&temp);
	world_normal = multiply_matrix_with_tuple(temp, obj_normal);
	world_normal[3] = 0;
	normal = normalize(world_normal);
	free_matrix(temp);
	free(obj_normal);
	free(obj_point);
	free(world_normal);
	return (normal);
}

static void	update_temp(float ***t)
{
	float	**temp;

	temp = transpose_matrix(*t);
	free_matrix(*t);
	*t = temp;
}
