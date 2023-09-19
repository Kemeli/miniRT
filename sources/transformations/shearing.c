#include <minirt.h>

double	**shearing(int axis, double value)
{
	double	**transform;

	transform = identity_matrix(4);
	if (axis == 0)
		transform[0][1] = value;
	else if (axis == 1)
		transform[0][2] = value;
	else if (axis == 2)
		transform[1][0] = value;
	else if (axis == 3)
		transform[1][2] = value;
	else if (axis == 4)
		transform[2][0] = value;
	else if (axis == 5)
		transform[2][1] = value;
	return (transform);
}
//só é usaso nos testes
