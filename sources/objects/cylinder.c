#include <minirt.h>

t_cylinder	*create_cylinder(void)
{
	t_cylinder	*cylinder;

	cylinder = ft_calloc(1, sizeof(t_cylinder));
	cylinder->minimum = -INFINITY;
	cylinder->maximum = INFINITY;
	cylinder->radius = 1;
	return (cylinder);
}
