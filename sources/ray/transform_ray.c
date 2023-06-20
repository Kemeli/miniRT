#include <minirt.h>

t_ray *transform_ray(t_ray *ray, float **matrix)
{
	t_ray	*ray_transformed;
	t_tuple	origin_transformed;
	t_tuple	direction_transformed;

	origin_transformed = multiply_matrix_with_tuple(matrix, ray->origin);
	direction_transformed = multiply_matrix_with_tuple(matrix, ray->direction);
	ray_transformed = create_ray(origin_transformed, direction_transformed);
	return (ray_transformed);
}
