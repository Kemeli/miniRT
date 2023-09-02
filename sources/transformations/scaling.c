#include <minirt.h>

t_matrix	scaling(double x, double y, double z)
{
	t_matrix scaling_matrix;

	scaling_matrix = identity_matrix(4);
	scaling_matrix[0][0] = x;
	scaling_matrix[1][1] = y;
	scaling_matrix[2][2] = z;
	return (scaling_matrix);
}
