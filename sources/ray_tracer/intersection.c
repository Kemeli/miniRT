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

void	free_intersections(t_intersect *list)
{
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
	else if ((*object)->shape == 'p')
		intersect = intersect_plane((*object), ray);
	else if ((*object)->shape == 'c')
		intersect = intersect_cylinder((*object), ray);
	return (intersect);
}
