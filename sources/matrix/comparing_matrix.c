#include <minirt.h>

int	compare_matrices(float **matrix_A, float **matrix_B)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (matrix_A[i])
	{
		if (matrix_A[i][j] != matrix_B[i][j])
			return (0);
		i++;
		j++;
	}
	return (1);
}
