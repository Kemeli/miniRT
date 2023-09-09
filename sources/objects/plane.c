#include <minirt.h>

t_plane	*create_plane(void)
{
	t_plane	*plane;

	plane = ft_calloc(1, sizeof(t_plane));
	plane->point = point(0, 0, 0);
	plane->orientation = vector(0, 1, 0); //ja está no normal_at
	return (plane);
}
