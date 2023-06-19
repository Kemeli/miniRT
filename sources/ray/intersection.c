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
	// if (discriminant < 0)
	// 	return (intersect); //infinity?
	// if (discriminant == 0)
	// {
	// 	intersect->t = -b / (2.0 * a);
	// 	intersect->t2= intersect->t;
	// 	intersect->count = 1;
	// 	return (intersect);
	// }

	sqrtd = sqrt(discriminant);
	intersect_list = add_intersection_to_list(
		intersect_list,
		new_intersection((-b - sqrtd) / (2.0 * a), &sphere)
	);
	intersect_list = add_intersection_to_list(
		intersect_list,
		new_intersection((-b + sqrtd) / (2.0 * a), &sphere)
	);
	return (intersect_list);
}

t_intersect	*intersect_sphere(t_sphere *sphere, t_ray ray)
{
	float		a;
	float		b;
	float		c;
	t_tuple		origin_to_center;
	t_intersect	*intersect;

	intersect = NULL;
	origin_to_center = subtract(ray.origin, sphere->center);
	a = dot(ray.direction, ray.direction);
	b = 2 * dot(ray.direction, origin_to_center);
	c = dot(origin_to_center, origin_to_center) - pow(sphere->radius, 2);
	intersect = handle_discriminant(a, b, c, sphere);
	free(origin_to_center);
	return (intersect);
}
