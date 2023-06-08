#include <minirt.h>

float	**scaling(float x, float y, float z)
{
	float **scaling_matrix;

	scaling_matrix = identity_matrix(4);
	scaling_matrix[0][0] = x;
	scaling_matrix[1][1] = y;
	scaling_matrix[2][2] = z;
	return (scaling_matrix);
}
