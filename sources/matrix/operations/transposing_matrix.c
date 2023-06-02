#include <minirt.h>

float	**transpose_matrix(float **matrix_A)
{
	float	**result;
	int		i;
	int		j;
	int		size;

	size = get_size(matrix_A);
	result = matrix(size);
	j = 0;
	while (j < size)
	{
		i = 0;
		while(i < size)
		{
			result[i][j] = matrix_A[j][i];
			i++;
		}
		j++;
	}
	return (result);
}
