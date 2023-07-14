#include <minirt.h>

t_comps	*prepare_computations(t_list *intersect, t_ray *ray)
{
	t_comps	*comps;
	float	dot_p;
	t_tuple	temp;

	comps = ft_calloc(1, sizeof(t_comps));
	comps->t = ((t_node *)intersect->content)->t;
	comps->object = ((t_node *)intersect->content)->object;
	comps->point = get_point_position(ray, comps->t);
	comps->eye = negative(ray->direction);
	comps->normal = normal_at(comps->object->sphere, comps->point);
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
	free_sphere(comps->object->sphere);
	free(comps->object);
	free(comps->point);
	free(comps->eye);
	free(comps->normal);
	free(comps);
}