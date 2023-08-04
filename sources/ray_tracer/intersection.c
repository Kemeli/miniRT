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

t_intersect	*intersect_cylinder(t_object *object, t_ray *ray)
{
	float		a;
	float		b;
	float		c;
	float		discriminant;
	t_intersect	*xs;
	float		t0;
	float		t1;
	float		tmp;
	float		y0;
	float		y1;

	xs = ft_calloc(1, sizeof(t_intersect));
	a = pow(ray->direction[0], 2) + pow(ray->direction[2], 2);
	if (a < EPSILON)
		return (xs);
	b = (2 * ray->origin[0] * ray->direction[0]) +
		(2 * ray->origin[2] * ray->direction[2]);
	c = pow(ray->origin[0], 2)  + pow(ray->origin[2], 2) - 1;
	discriminant = pow(b, 2) - (4 * a * c);
	if (discriminant < 0)
		return (xs);
	t0 = (-b - sqrt(discriminant)) / (2 * a);
	t1 = (-b + sqrt(discriminant)) / (2 * a);
	if (t0 > t1)
	{
		tmp = t0;
		t0 = t1;
		t1 = tmp;
	}
	y0 = ray->origin[1] + (t0 * ray->direction[1]);
	if (object->cylinder->minimum < y0 && y0 < object->cylinder->maximum)
		xs->head = new_intersection(t0, object);
	y1 = ray->origin[1] + (t1 * ray->direction[1]);
	if (object->cylinder->minimum < y1 && y1 < object->cylinder->maximum)
		ft_lstadd_back(&xs->head, new_intersection(t1, object));
	xs->count = ft_lstsize(xs->head);
	return (xs);
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
