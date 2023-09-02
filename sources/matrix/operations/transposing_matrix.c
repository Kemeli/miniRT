#include <minirt.h>

double	**transpose_matrix(t_matrix matrix_A)
{
	t_matrix	result;
	int			i;
	int			j;
	int			size;

	size = get_size(matrix_A);
	result = matrix(size);
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			result[i][j] = matrix_A[j][i];
			i++;
		}
		j++;
	}
	return (result);
}
