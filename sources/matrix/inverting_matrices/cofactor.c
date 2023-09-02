#include <minirt.h>

double	cofactor(t_matrix matrix, int i, int j)
{
	double	minor_result;

	minor_result = minor(matrix, i, j);
	if ((i + j) % 2 != 0)
		minor_result *= -1;
	return (minor_result);
}
