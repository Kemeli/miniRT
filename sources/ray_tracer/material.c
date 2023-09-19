#include <minirt.h>

t_material	*material(void)
{
	t_material	*material;

	material = ft_calloc(1, sizeof(t_material));
	material->color = NULL;
	material->ambient = NULL;
	material->diffuse = 0.9f;
	material->specular = 0.9f;
	material->shininess = 200.0f;
	return (material);
}

void	free_material(t_material *m)
{
	free(m->color);
	free(m->ambient);
	free(m);
}
