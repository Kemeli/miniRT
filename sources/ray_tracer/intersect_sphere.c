#include <minirt.h>

void	free_sphere_intersection(
	t_tuple origin_to_center,
	t_tuple abc
)
{
	free(origin_to_center);
	free(abc);
}

t_intersect	*handle_discriminant(
	float a,
	float b,
	float c,
	t_object *object
)
{
	float		sqrtd;
	float		discriminant;
	t_intersect	*intersect_list;
	t_list		*first_inter;
	t_list		*second_inter;

	first_inter = NULL;
	second_inter = NULL;
	intersect_list = ft_calloc(1, sizeof(t_intersect));
	discriminant = pow(b, 2) - 4 * a * c;
	sqrtd = sqrt(discriminant);
	first_inter = new_intersection((-b - sqrtd) / (2.0 * a), object);
	second_inter = new_intersection((-b + sqrtd) / (2.0 * a), object);
	ft_lstadd_back(&first_inter, second_inter);
	intersect_list->head = first_inter;
	if (discriminant == 0)
		intersect_list->count = 1;
	else if (discriminant > 0)
		intersect_list->count = 2;
	return (intersect_list);
}

t_intersect	*intersect_sphere(t_object *object)
{
	t_tuple		abc;
	t_tuple		orig_center;
	t_intersect	*intersect;

	abc = point(0, 0, 0);
	intersect = NULL;
	orig_center = subtract(object->saved_ray->origin, object->sphere->center);
	abc[0] = dot(object->saved_ray->direction, object->saved_ray->direction);
	abc[1] = 2 * dot(object->saved_ray->direction, orig_center);
	abc[2] = dot(orig_center, orig_center) - pow(object->sphere->radius, 2);
	intersect = handle_discriminant(abc[0], abc[1], abc[2], object);
	free_sphere_intersection(orig_center, abc);
	return (intersect);
}
