#include <minirt.h>

t_point_light	*point_light(t_tuple position, t_tuple intensity)
{
	t_point_light	*point_light;

	point_light = ft_calloc(1, sizeof(t_point_light));
	point_light->position = position;
	point_light->intensity = intensity;
	return (point_light);
}

t_material	*material(void)
{
	t_material	*material;

	material = ft_calloc(1, sizeof(t_material));
	material->color = color(1, 1, 1);
	material->ambient = 0.1f;
	material->diffuse = 0.9f;
	material->specular = 0.9f;
	material->shininess = 200.0f;
	return (material);
}

t_tuple	lighting(t_lighting *)
{
	t_tuple	response;

	return (response);
}
