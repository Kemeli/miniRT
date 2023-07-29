#include <minirt.h>

t_tuple	color_at(t_world *w, t_ray *r)
{
	t_intersect	*xs;
	t_comps		*comps;
	t_tuple		c;
	t_node		*the_hit;

	xs = intersect_world(w, r);
	the_hit = hit(xs);
	if (the_hit)
	{
		comps = prepare_computations(the_hit, r);
		c = shade_hit(w, comps);
		free_comps(comps);
	}
	else
		c = color(0, 0, 0);
	free_intersections(xs);
	return (c);
}
