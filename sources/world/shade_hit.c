#include <minirt.h>

t_tuple	shade_hit(t_world *world, t_comps *comps)
{
	t_lighting	*c_lighting;
	t_tuple		color;

	c_lighting = ft_calloc(1, sizeof(t_lighting));
	c_lighting->material = comps->object->sphere->material;
	c_lighting->light = world->light;
	c_lighting->position = comps->point;
	c_lighting->eye = comps->eye;
	c_lighting->normal = comps->normal;
	c_lighting->in_shadow = is_shadowed(world, comps->over_point);
	color = lighting(c_lighting);
	free(c_lighting);
	return (color);
}
