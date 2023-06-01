#include <minirt.h>

static int	matrix_size(float **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

int	compare_matrices(float **matrix_A, float **matrix_B)
{
	int	i;
	int	j;
	int	size;
	float epsilon = 0.00001;

	i = 0;
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
