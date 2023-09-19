#include <minirt.h>

void	free_sphere_intersection(
	t_tuple origin_to_center,
	t_tuple abc
)
{
	free(origin_to_center);
	free(abc);
}

void	append_node(t_node **head, t_node *new)
{
	t_node	*aux;

	aux = *head;
	if (!aux)
		*head = new;
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
}

t_intersect	*handle_discriminant(
	double a,
	double b,
	double c,
	t_object *object
)
{
	double		sqrtd;
	double		discriminant;
	t_node		*next_xs;
	t_intersect	*xs;

	xs = ft_calloc(1, sizeof(t_intersect));
	discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant < 0)
		return (xs);
	sqrtd = sqrt(discriminant);
	if (discriminant == 0)
	{
		xs->count = 1;
		xs->head = new_intersection((-b - sqrtd) / (2.0 * a), object);
	}
	else if (discriminant > 0)
	{
		xs->count = 2;
		xs->head = new_intersection((-b - sqrtd) / (2.0 * a), object);
		next_xs = new_intersection((-b + sqrtd) / (2.0 * a), object);
		append_node(&xs->head, next_xs);
	}
	return (xs);
}

t_intersect	*intersect_sphere(t_object *object, t_ray *ray)
{
	t_tuple		abc;
	t_tuple		orig_center;
	t_intersect	*intersect_lst;

	abc = point(0, 0, 0);
	intersect_lst = NULL;
	orig_center = subtract(ray->origin, object->sphere->center);
	abc[0] = dot(ray->direction, ray->direction);
	abc[1] = 2 * dot(ray->direction, orig_center);
	abc[2] = dot(orig_center, orig_center) - 1;
	intersect_lst = handle_discriminant(abc[0], abc[1], abc[2], object);
	free_sphere_intersection(orig_center, abc);
	return (intersect_lst);
}
