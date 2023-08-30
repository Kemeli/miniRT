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
	float a,
	float b,
	float c,
	t_object *object
)
{
	float		sqrtd;
	float		discriminant;
	t_intersect	*intersect_lst;
	t_node		*first_inter;
	t_node		*second_inter;

	intersect_lst = ft_calloc(1, sizeof(t_intersect));
	intersect_lst->count = 0;
	discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant < 0)
		return (intersect_lst);
	sqrtd = sqrt(discriminant);
	if (discriminant == 0)
	{
		intersect_lst->count = 1;
		first_inter = new_intersection((-b - sqrtd) / (2.0 * a), object);
		append_node(&intersect_lst->head, first_inter);
	}
	else if (discriminant > 0)
	{
		intersect_lst->count = 2;
		first_inter = new_intersection((-b - sqrtd) / (2.0 * a), object);
		intersect_lst->head = first_inter;
		second_inter = new_intersection((-b + sqrtd) / (2.0 * a), object);
		append_node(&first_inter, second_inter);
	}
	return (intersect_lst);
}

t_intersect	*intersect_sphere(t_object *object)
{
	t_tuple		abc;
	t_tuple		orig_center;
	t_intersect	*intersect_lst;

	abc = point(0, 0, 0);
	intersect_lst = NULL;
	orig_center = subtract(object->saved_ray->origin, object->sphere->center);
	abc[0] = dot(object->saved_ray->direction, object->saved_ray->direction);
	abc[1] = 2 * dot(object->saved_ray->direction, orig_center);
	abc[2] = dot(orig_center, orig_center) - pow(object->sphere->radius, 2);
	intersect_lst = handle_discriminant(abc[0], abc[1], abc[2], object);
	free_sphere_intersection(orig_center, abc);
	return (intersect_lst);
}
