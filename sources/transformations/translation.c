#include <minirt.h>

double	**translation(double x, double y, double z)
{
	double	**translation_matrix;

	translation_matrix = identity_matrix(4);
	translation_matrix[0][3] = x;
	translation_matrix[1][3] = y;
	translation_matrix[2][3] = z;
	return (translation_matrix);
}
