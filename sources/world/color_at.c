#include <minirt.h>

t_tuple	color_at(t_world *w, t_ray *r)
{
	t_intersect	*xs;
	t_comps		*comps;
	t_tuple		c;

	xs = intersect_world(w, r);
	if(hit(xs))
	{
		comps = prepare_computations(xs->head, r);
		c = shade_hit(w, comps);
	}
	else
		c = color(0, 0, 0);
	free_intersections(xs);
	return (c);
}
