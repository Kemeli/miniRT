#include <minirt.h>

t_comps	*prepare_computations(t_node *hit, t_ray *ray)
{
	t_comps	*comps;
	float	dot_p;
	t_tuple	temp;

	comps = ft_calloc(1, sizeof(t_comps));
	comps->t = hit->t;
	comps->object = hit->object;
	comps->point = get_point_position(ray, comps->t);
	comps->eye = negative(ray->direction);
	comps->normal = normal_at(comps->object, comps->point);
	comps->inside = FALSE;
	dot_p = dot(comps->normal, comps->eye);
	if (dot_p < 0)
	{
		comps->inside = True;
		temp = comps->normal;
		comps->normal = negative(temp);
		free(temp);
	}
	return (comps);
}

void	free_comps(t_comps *comps)
{
	free(comps->point);
	free(comps->eye);
	free(comps->normal);
	free(comps);
}
