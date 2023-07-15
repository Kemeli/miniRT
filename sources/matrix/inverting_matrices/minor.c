#include <minirt.h>

float	minor(t_matrix matrix, int i, int j)
{
	t_matrix	m;
	float		result;

	m = submatrix(matrix, i, j);
	result = determinant(m);
	free_matrix(m);
	return (result);
}
