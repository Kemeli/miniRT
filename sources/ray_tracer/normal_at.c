#include <minirt.h>

t_tuple	normal_at(t_sphere *sphere, t_tuple world_point)
{
	t_tuple	normal;
	t_tuple	obj_point;
	t_tuple	obj_normal;
	t_tuple	world_normal;
	float	**temp;
	float	**temp2;

	temp = inverse(sphere->transform);
	obj_point = multiply_matrix_with_tuple(temp, world_point);
	obj_normal = subtract(obj_point, sphere->center);
	temp2 = transpose_matrix(temp);
	world_normal = multiply_matrix_with_tuple(temp2, obj_normal);
	world_normal[3] = 0;
	normal = normalize(world_normal);
	free_matrix(temp);
	free_matrix(temp2);
	free(obj_normal);
	free(obj_point);
	free(world_normal);
	return (normal);
}
