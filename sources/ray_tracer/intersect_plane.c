#include <minirt.h>

t_intersect	*intersect_plane(t_object *object, t_ray *ray)
{
	t_intersect	*intersect;
	double		t;

	intersect = ft_calloc(1, sizeof(t_intersect));
	if (fabs(ray->direction[1]) < EPSILON)
		return (intersect);
	t = -ray->origin[1] / ray->direction[1];
	intersect->head = new_intersection(t, object);
	intersect->count = 1;
	return (intersect);
}
