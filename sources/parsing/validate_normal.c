#include <minirt.h>

static char	validate_range(float *n)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (fabs(n[i]) > 1.0f && fabs(n[0]) - 1.0f > EPSILON)
			return (0);
		i++;
	}
	return (1);
}

t_tuple	validate_normal(char *str)
{
	float	n[3];
	float *normal;

	normal = validate_tuple(str, n);
	if (normal && validate_range(normal))
		return (vector(normal[0], normal[1], normal[2]));
	return (NULL);
}
