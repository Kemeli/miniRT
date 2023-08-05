#include <minirt.h>

t_sphere	*create_sphere(void) //passar um valor unuico cade vez que a esfera é criada
{
	t_sphere	*sphere;

	sphere = ft_calloc(1, sizeof(t_sphere));
	sphere->center = point(0, 0, 0);
	sphere->radius = 1;
	return (sphere);
}

void	free_sphere(t_sphere *s)
{
	free(s->center);
	free(s);
}
