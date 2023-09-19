#include <minirt.h>

t_point_light	*point_light(t_tuple position, t_tuple intensity)
{
	t_point_light	*point_light;

	point_light = ft_calloc(1, sizeof(t_point_light));
	point_light->position = position;
	point_light->intensity = intensity;
	return (point_light);
}
