#include <minirt.h>

void	free_shadow(t_ray *r, t_intersect *intersect, t_tuple v)
{
	free_ray(r);
	free_intersections(intersect);
	free(v);
}

char	is_shadowed(t_world *world, t_tuple point)
{
	t_tuple		v;
	t_tuple		direction;
	t_ray		*ray;
	t_intersect	*intersect;
	t_node		*try_hit;

	v = subtract(world->light->position, point);
	direction = normalize(v);
	ray = create_ray(point, direction);
	intersect = intersect_world(world, ray);
	try_hit = hit(intersect);
	if (try_hit && try_hit->t < magnitude(v)) //mag = distance
	{
		free_shadow(ray, intersect, v);
		return (TRUE);
	}
	free_shadow(ray, intersect, v);
	return (FALSE);
}
