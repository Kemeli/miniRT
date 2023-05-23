#include <minirt.h>

float	**matrix(unsigned int n)
{
	float			**m;
	unsigned int	i;

	i = 0;
	m = malloc(sizeof(float **) * n);
	while (i < n)
	{
		m[i] = malloc(sizeof(float *) * n);
		i++;
	}
	return (m);
}
