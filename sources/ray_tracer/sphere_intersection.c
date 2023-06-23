#include <minirt.h>

t_intersect *handle_discriminant(
	float a,
	float b,
	float c,
	t_sphere *sphere
)
{
	float	sqrtd;
	float	discriminant;
	t_intersect	*intersect_list;

	intersect_list = NULL;
	discriminant = pow(b, 2) - 4 * a * c;
	sqrtd = sqrt(discriminant);
	intersect_list = add_intersection_to_list(
		intersect_list,
		new_intersection((-b - sqrtd) / (2.0 * a), &sphere)
	);
	intersect_list = add_intersection_to_list(
		intersect_list,
		new_intersection((-b + sqrtd) / (2.0 * a), &sphere)
	);
	if (discriminant == 0)
		intersect_list->count = 1;
	else if (discriminant > 0)
		intersect_list->count = 2;
	return (intersect_list);
}

t_intersect	*intersect_sphere(t_sphere *sphere, t_ray *ray)
{
	float		a;
	float		b;
	float		c;
	t_ray		*transformed_ray;
	t_tuple		origin_to_center;
	t_intersect	*intersect;
	float		**inv;

	inv = inverse(sphere->transform);
	intersect = NULL;
	transformed_ray = transform_ray(ray, inv);
	origin_to_center = subtract(transformed_ray->origin, sphere->center);
	a = dot(transformed_ray->direction, transformed_ray->direction);
	b = 2 * dot(transformed_ray->direction, origin_to_center);
	c = dot(origin_to_center, origin_to_center) - pow(sphere->radius, 2);
	intersect = handle_discriminant(a, b, c, sphere);
	free(origin_to_center);
	free(transformed_ray->origin);
	free(transformed_ray->direction);
	free(transformed_ray);
	free_matrix(inv);
	return (intersect);
}