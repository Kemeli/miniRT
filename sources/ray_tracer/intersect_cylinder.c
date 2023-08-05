#include <minirt.h>

int	check_cap(t_ray *ray, float t)
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

void	intersect_caps(t_object *object, t_ray *ray, t_intersect *xs)
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
	if (a < EPSILON && !object->cylinder->closed)
		return (xs);
	b = (2 * ray->origin[0] * ray->direction[0]) +
		(2 * ray->origin[2] * ray->direction[2]);
	c = pow(ray->origin[0], 2)  + pow(ray->origin[2], 2) - 1;
	discriminant = pow(b, 2) - (4 * a * c);
	if (discriminant < 0 && !object->cylinder->closed)
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
	if (object->cylinder->closed)
		intersect_caps(object, ray, xs);
	xs->count = ft_lstsize(xs->head);
	return (xs);
}
