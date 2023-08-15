#include <minirt.h>

t_tuple	validate_coordinates(char *str)
{
	float	n[3];

	if (!validate_tuple(str, n))
		return (NULL);
	return (point(n[0], n[1], n[2]));
}
