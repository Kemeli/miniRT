#include <minirt.h>

float	**multiply_matrix_scalar(float **original_matrix, float scalar)
{
	int		i;
	int		j;
	int		size;
	float	**result;

	size = get_size(original_matrix);
	result = matrix(size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			result[i][j] = original_matrix[i][j] * scalar;
			j++;
		}
		i++;
	}
	return (result);
}

float	**inverse(float **original_matrix)
{
	float	**cofactor_matrix;
	float	**transposed_matrix;
	int		size;
	int		i;
	int		j;

	size = get_size(original_matrix);
	cofactor_matrix = matrix(size);
	i = 0;
	while(i < size)
	{
		j = 0;
		while (j < size)
		{
			cofactor_matrix[i][j] = cofactor(original_matrix, i, j);
			j++;
		}
		i++;
	}
	transposed_matrix = transpose_matrix(cofactor_matrix);
	free_matrix(cofactor_matrix);
	return (multiply_matrix_scalar(transposed_matrix, 1 / determinant(original_matrix)));
}
