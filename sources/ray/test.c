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
		return (intersect); //infinity?
	if (discriminant == 0)
	{
		intersect->t = -b / (2.0 * a);
		intersect->t2= intersect->t;
		intersect->count = 1;
		return (intersect);
	}
	sqrtd = sqrt(discriminant);
	intersect->t = (-b - sqrtd) / (2.0 * a);
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

void	handle_sphere_intersection()

t_intersect	*intersection(t_object *object, t_ray ray)
{
	t_intersect	*intersect;
	t_sphere	s;

	intersect = NULL;
	if (object->type == SPHERE)
	{
		handle_sphere_intersection(object);
		intersect = ft_calloc(1, sizeof(t_intersect));
		s = create_sphere();
		intersect = get_values(intersect, s, ray);
	}
	return (intersect);
}

//#############################################################################

t_intersect	*create_intersection(float t, void *object)
{
	t_intersect	*intersect;

	intersect = ft_calloc(1, sizeof(t_intersect));
	intersect->t = t;
	intersect->count = 1;
	intersect->object = object;
	intersect->next = NULL;
	return (intersect);
}

t_intersect	*add_intersection_to_list(t_intersect *list, t_intersect *new)
{
	t_intersect	*aux;

	if (list == NULL)
		return (new);
	else
	{
		aux = list;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	return (list);
}

void	free_list(t_intersect *list)
{
	t_intersect	*aux;

	aux = list;
	while (list)
	{
		aux = list->next;
		free(list);
		list = aux;
	}
}
