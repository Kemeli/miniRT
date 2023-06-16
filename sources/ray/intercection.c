#include <minirt.h>

t_intersect *handle_discriminant(
	t_intersect *intersect,
	float a,
	float b,
	float c
)
{
	float	sqrtd;
	float	discriminant;

	discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant < 0)
		return (intersect);
	if (discriminant == 0)
	{
		intersect->t1 = -b / (2.0 * a);
		intersect->t2= intersect->t1;
		intersect->count = 1;
		return (intersect);
	}
	sqrtd = sqrt(discriminant);
	intersect->t1 = (-b - sqrtd) / (2.0 * a);
	intersect->t2= (-b + sqrtd) / (2.0 * a);
	intersect->count = 2;
	return (intersect);
}

t_intersect	*get_values(t_intersect *intersect, t_sphere sphere, t_ray ray)
{
	float		a;
	float		b;
	float		c;
	t_tuple		origin_to_center;

	origin_to_center = subtract(ray.origin, sphere.center);
	a = dot(ray.direction, ray.direction);
	b = 2 * dot(ray.direction, origin_to_center);
	c = dot(origin_to_center, origin_to_center) - pow(sphere.radius, 2);
	intersect = handle_discriminant(intersect, a, b, c);
	free(origin_to_center);
	return (intersect);
}

t_intersect	*intersection(t_sphere sphere, t_ray ray)
{
	t_intersect	*intersect;

	intersect = ft_calloc(1, sizeof(t_intersect));
	intersect = get_values(intersect, sphere, ray);
	return (intersect);
}
