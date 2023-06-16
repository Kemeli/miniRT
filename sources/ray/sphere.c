#include <minirt.h>

t_sphere	create_sphere(void) //passar um valor unuico cade vez que a esfera é criada
{
	t_sphere	sphere;

	sphere.center = point(0, 0, 0);
	sphere.radius = 1;
	return (sphere);
}
