#include <minirt.h>

float	**matrix(unsigned int n)
{
	float			**m;
	unsigned int	i;

	if (n == 0)
		return (NULL);
	i = 0;
	m = malloc(sizeof(float **) * (n + 1));
	while (i < n)
	{
		m[i] = malloc(sizeof(float *) * n);
		i++;
	}
	m[i] = NULL;
	return (m);
}

float	**identity_matrix(unsigned int n)
{
	float	**m;
	int		i;
	int		j;

	m = matrix(n);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			m[i][j] = 0;
			if (i == j)
				m[i][j] = 1;
			j++;
		}
		i++;
	}
	return (m);
}

void	free_matrix(float **m)
{
	unsigned int	i;

	i = 0;
	while (m[i])
	{
		free(m[i]);
		i++;
	}
	free(m);
}
