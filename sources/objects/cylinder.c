#include <minirt.h>

t_cylinder	*create_cylinder(void)
{
	t_cylinder	*cylinder;

	cylinder = ft_calloc(1, sizeof(t_cylinder));
	cylinder->radius = 1;
	cylinder->height = 1;
	return (cylinder);
}
