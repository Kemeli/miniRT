#include <minirt.h>

double	cofactor(t_matrix matrix, int i, int j)
{
	double	minor_result;

	minor_result = minor(matrix, i, j);
	if ((i + j) % 2 != 0)
		minor_result *= -1;
	return (minor_result);
}

t_matrix	cofactor_matrix(t_matrix m, int size)
{
	t_matrix	result_matrix;
	int			i;
	int			j;

	result_matrix = matrix(size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			result_matrix[i][j] = cofactor(m, i, j);
	}
	return (result_matrix);
}
