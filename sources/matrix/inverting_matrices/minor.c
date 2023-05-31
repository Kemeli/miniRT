#include <minirt.h>

float	minor(float **matrix, int i, int j)
{
	float	**M;
	float	result;

	M = submatrix(matrix, i, j);
	result = determinant(M);
	free_matrix(M);
	return (result);
}
