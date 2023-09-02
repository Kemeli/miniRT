#include <minirt.h>

t_matrix	matrix(unsigned int n)
{
	t_matrix		m;
	unsigned int	i;

	if (n == 0)
		return (NULL);
	i = 0;
	m = ft_calloc(n + 1, sizeof(double *));
	while (i < n)
	{
		m[i] = ft_calloc(n + 1, sizeof(double));
		i++;
	}
	m[i] = NULL;
	return (m);
}

double	**identity_matrix(unsigned int n)
{
	t_matrix		m;
	unsigned int	i;
	unsigned int	j;

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

void	free_matrix(t_matrix m)
{
	unsigned int	i;

	i = 0;
	while (m[i])
	{
		ft_free_ptr((void *) &m[i]);
		i++;
	}
	ft_free_ptr((void *) &m);
}
