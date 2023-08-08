#include <minirt.h>

static char	check_cap(t_ray *ray, float t)
{
	float	x;
	float	z;
	float	uno;
	float	result;

	uno = 1.0f;
	x = ray->origin[0] + (t * ray->direction[0]);
	z = ray->origin[2] + (t * ray->direction[2]);
	result = pow(x, 2) + pow(z, 2);
	if (result > uno)
		return (fabs(result - uno) < EPSILON);
	return (result <= uno);
}

static void	intersect_caps(t_object *object, t_ray *ray, t_intersect *xs)
{
	float	t;

	if (!object->cylinder->closed || fabs(ray->direction[1]) < EPSILON)
		return ;
	t = (object->cylinder->minimum - ray->origin[1]) / ray->direction[1];
	if (check_cap(ray, t))
	{
		ft_lstadd_back(&xs->head, new_intersection(t, object));
	}
	t = (object->cylinder->maximum - ray->origin[1]) / ray->direction[1];
	if (check_cap(ray, t))
	{
		ft_lstadd_back(&xs->head, new_intersection(t, object));
	}
}

static void	create_intersection(
	t_object *object,
	t_ray *ray,
	float *t,
	t_intersect **xs)
{
	float	y[2];

	y[0] = ray->origin[1] + (t[0] * ray->direction[1]);
	if (object->cylinder->minimum < y[0] && y[0] < object->cylinder->maximum)
		(*xs)->head = new_intersection(t[0], object);
	y[1] = ray->origin[1] + (t[1] * ray->direction[1]);
	if (object->cylinder->minimum < y[1] && y[1] < object->cylinder->maximum)
		ft_lstadd_back(&(*xs)->head, new_intersection(t[1], object));
	if (object->cylinder->closed)
		intersect_caps(object, ray, (*xs));
	(*xs)->count = ft_lstsize((*xs)->head);
}

t_intersect	*intersect_cylinder(t_object *object, t_ray *ray)
{
	float		abc[3];
	float		discriminant;
	float		t[2];
	t_intersect	*xs;

	xs = ft_calloc(1, sizeof(t_intersect));
	abc[0] = pow(ray->direction[0], 2) + pow(ray->direction[2], 2);
	if (abc[0] < EPSILON && !object->cylinder->closed)
		return (xs);
	abc[1] = (2 * ray->origin[0] * ray->direction[0])
		+ (2 * ray->origin[2] * ray->direction[2]);
	abc[2] = pow(ray->origin[0], 2) + pow(ray->origin[2], 2) - 1;
	discriminant = pow(abc[1], 2) - (4 * abc[0] * abc[2]);
	if (discriminant < 0 && !object->cylinder->closed)
		return (xs);
	t[0] = (-abc[1] - sqrt(discriminant)) / (2 * abc[0]);
	t[1] = (-abc[1] + sqrt(discriminant)) / (2 * abc[0]);
	if (t[0] > t[1])
		ft_swap(&t[0], &t[1]);
	create_intersection(object, ray, t, &xs);
	return (xs);
}
