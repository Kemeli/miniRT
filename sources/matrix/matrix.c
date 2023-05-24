#include <minirt.h>

float	**matrix(unsigned int n)
{
	float			**m;
	unsigned int	i;

	if (n == 0)
		return (NULL);
	i = 0;
	m = malloc(sizeof(float **) * n);
	while (i < n)
	{
		m[i] = malloc(sizeof(float *) * n);
		i++;
	}
	return (m);
}

void	free_matrix(float **m, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		free(m[i]);
		i++;
	}
	free(m);
}
