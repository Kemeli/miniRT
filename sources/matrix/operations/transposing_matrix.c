#include <minirt.h>

float	**transpose_matrix(float **matrix_A)
{
	float	**result;
	int		i;
	int		j;

	result = matrix(4);
	j = 0;
	while (j < 4)
	{
		i = 0;
		while(i < 4)
		{
			result[i][j] = matrix_A[j][i];
			i++;
		}
		j++;
	}
	return (result);
}
