#include <minirt.h>

t_sphere	*create_sphere(void) //passar um valor unuico cade vez que a esfera é criada
{
	t_sphere	*sphere;

	sphere = ft_calloc(1, sizeof(t_sphere));
	sphere->center = point(0, 0, 0);
	sphere->radius = 1;
	sphere->transform = identity_matrix(4);
	sphere->material = material();
	sphere->change_my_material = change_material;
	return (sphere);
}

void	change_material(t_sphere *s, t_material *m)
{
	free(s->material->color);
	free(s->material);
	s->material = m;
}
