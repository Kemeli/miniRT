#include <minirt.h>

float	cofactor(float **matrix, int i, int j)
{
	float	minor_result;

	minor_result = minor(matrix, i, j);
	if ((i + j) % 2 != 0)
		minor_result *= -1;
	return (minor_result);
}
