#include <minirt.h>

double	minor(t_matrix matrix, int i, int j)
{
	t_matrix	m;
	double		result;

	m = submatrix(matrix, i, j);
	result = get_determinant(m);
	free_matrix(m);
	return (result);
}
