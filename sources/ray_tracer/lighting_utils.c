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
	material->ambient = color(0.1f, 0.1f, 0.1f);
	material->diffuse = 0.9f;
	material->specular = 0.9f;
	material->shininess = 200.0f;
	return (material);
}

t_tuple	ligth_vector(t_lighting *l)
{
	t_tuple	sub;
	t_tuple	light_v;

	sub = subtract(l->light->position, l->position);
	light_v = normalize(sub);
	free(sub);
	return (light_v);
}

void	free_material(t_material *m)
{
	free(m->color);
	free(m);
}

void	free_lighting(t_lighting *l)
{
	free(l->eye);
	free(l->light);
	free(l->normal);
	free(l->position);
	free_material(l->material);
	free(l);
}
