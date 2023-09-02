#include <minirt.h>

static int	matrix_size(t_matrix matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

int	compare_matrices(t_matrix matrix_A, t_matrix matrix_B)
{
	int		i;
	int		j;
	int		size;
	double	epsilon;

	i = 0;
	epsilon = 0.00001;
	size = matrix_size(matrix_A);
	while (matrix_A[i])
	{
		j = 0;
		while (j < size)
		{
			if (fabs(matrix_A[i][j] - matrix_B[i][j]) > epsilon)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
