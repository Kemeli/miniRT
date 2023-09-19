#include <minirt.h>

t_tuple	ligth_vector(t_lighting *l)
{
	t_tuple	sub;
	t_tuple	light_v;

	sub = subtract(l->light->position, l->position);
	light_v = normalize(sub);
	free(sub);
	return (light_v);
}

t_tuple	multiply_color(t_tuple color, t_tuple amb)
{
	t_tuple	response;

	response = ft_calloc(4, sizeof(double));
	response[0] = color[0] * amb[0];
	response[1] = color[1] * amb[1];
	response[2] = color[2] * amb[2];
	response[3] = 0;
	return (response);
}
