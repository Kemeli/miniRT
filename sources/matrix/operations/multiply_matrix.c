#include <minirt.h>
#include <stdio.h>

static float	multiply_elements(float **matrix_A,
	float **matrix_B, int i, int j)
{
	float	first;
	float	second;
	float	third;
	float	fourth;

	first = matrix_A[i][0] * matrix_B[0][j];
	second = matrix_A[i][1] * matrix_B[1][j];
	third = matrix_A[i][2] * matrix_B[2][j];
	fourth = matrix_A[i][3] * matrix_B[3][j];
	return (first + second + third + fourth);
}

float	**multiply_matrix(float **matrix_A, float **matrix_B)
{
	int		i;
	int		j;
	float	**result_matrix;

	result_matrix = matrix(4);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result_matrix[i][j] = multiply_elements(matrix_A, matrix_B, i, j);
			j++;
		}
		i++;
	}
	return (result_matrix);
}
