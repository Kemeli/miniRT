#include <minirt.h>

t_node	*new_intersection(double t, t_object *object)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	node->t = t;
	node->object = object;
	node->next = NULL;
	return (node);
}

void	free_intersections(t_intersect *list)
{
	t_node	*aux;

	while (list->head)
	{
		aux = list->head;
		list->head = list->head->next;
		free(aux);
	}
	free(list);
}

t_intersect	*intersect(t_object **object, t_ray *ray)
{
	t_intersect	*intersect;

	// if((*object)->saved_ray)
	// 	free_ray((*object)->saved_ray);

	(*object)->saved_ray = transform_ray(ray, (*object)->inverse);
	intersect = NULL;
	if ((*object)->shape == 's')
		intersect = intersect_sphere((*object));
	else if ((*object)->shape == 'p')
		intersect = intersect_plane((*object), ray);
	else if ((*object)->shape == 'c')
		intersect = intersect_cylinder((*object), ray); //falta verificar aqui
	return (intersect);
}
