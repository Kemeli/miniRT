#include <minirt.h>

t_ray	create_ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_tuple	get_point_position(t_ray ray, float t)
{
	t_tuple	position;
	t_tuple	multiplication_result;

	multiplication_result = multiply_tuple_by_scalar(ray.direction, t);
	position = tuple_addition(ray.origin, multiplication_result);
	free(multiplication_result);
	return (position);
}
