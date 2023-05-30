#include "minirt.h"

float	determinant_2X2_matrix(float **matrix)
{
	float	result;
	float	first_diagonal;
	float	second_diagonal;

	first_diagonal = matrix[0][0] * matrix[1][1];
	second_diagonal = matrix[0][1] * matrix[1][0];
	result = first_diagonal - second_diagonal;
	return (result);
}
