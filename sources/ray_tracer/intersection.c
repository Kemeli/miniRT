#include <minirt.h>

t_list	*new_intersection(float t, t_object *object)
{
	t_node	*content;
	t_list	*list;

	content = ft_calloc(1, sizeof(t_node));
	content->t = t;
	content->object = object;
	list = ft_lstnew(content);
	return (list);
}

t_intersect	*intersect_plane(t_object *object, t_ray *ray)
{
	t_intersect	*intersect;
	float		t;

	intersect = ft_calloc(1, sizeof(t_intersect));
	if (fabs(ray->direction[1]) < EPSILON)
		return (intersect);
	t = -ray->origin[1] / ray->direction[1];
	intersect->head = new_intersection(t, object);
	intersect->count = 1;
	return (intersect);
}

void	free_intersections(t_intersect *list)
{
	//free_ray(((t_node *)list->head->content)->object->saved_ray);
	ft_lstclear(&list->head, free);
	free(list);
}

t_intersect	*intersect(t_object **object, t_ray *ray)
{
	t_intersect	*intersect;
	t_matrix	inv;

	if((*object)->saved_ray)
		free_ray((*object)->saved_ray);
	inv = inverse((*object)->transform);
	(*object)->saved_ray = transform_ray(ray, inv);
	free_matrix(inv);
	intersect = NULL;
	if ((*object)->shape == 's')
		intersect = intersect_sphere((*object));
	if ((*object)->shape == 'p')
		intersect = intersect_plane((*object), ray);

	/*com calloc os que n receberem memoria vão estar apontando para NULL*/
	// else if (object->plane)
	// 	intersect = *intersect_plane(object, ray);
	// else if (object->cylinder)
	// 	intersect = *intersect_cylinder(object, ray);
	// else
	// {
	// 	intersect.count = 0;
	// 	intersect.head = NULL;
	// }
	return (intersect);
}
