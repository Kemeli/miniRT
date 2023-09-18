#include <minirt.h>

static t_matrix	get_x_y_rotation(t_tuple orientation)
{
	t_matrix	rotate_x;
	t_matrix	rotate_y;
	t_matrix	rotate;

	rotate_x = rotation_x(M_PI / 2);
	rotate_y = rotation_y(atan(orientation[0]/ orientation[2]));
	rotate = multiply_matrix(rotate_y, rotate_x);
	free_matrix(rotate_x);
	free_matrix(rotate_y);
	return (rotate);
}

static t_matrix	get_z_x_rotation(t_tuple orientation)
{
	t_matrix	rotate_x;
	t_matrix	rotate_z;
	t_matrix	rotate;

	rotate_x = rotation_x(atan(orientation[2] / orientation[1]));
	rotate_z = rotation_z(atan(-orientation[0] / orientation[1]));
	rotate = multiply_matrix(rotate_z, rotate_x);
	free_matrix(rotate_x);
	free_matrix(rotate_z);
	return (rotate);
}

t_matrix get_rotation_matrix(t_tuple orientation)
{
	if (compare_doubles(orientation[0], 0) && compare_doubles(orientation[2], 0))
	{
		if (compare_doubles(orientation[1], 1))
			return identity_matrix(4);
		else if (compare_doubles(orientation[1], -1))
			return rotation_x(M_PI);
	}
	else if (compare_doubles(orientation[1], 0))
	{
		if (compare_doubles(orientation[0], 1))
			return rotation_z(-M_PI / 2);
		else if (compare_doubles(orientation[0], -1))
			return rotation_z(M_PI / 2);
		else if (compare_doubles(orientation[2], 1))
			return rotation_x(M_PI / 2);
		else if (compare_doubles(orientation[2], -1))
			return rotation_x(-M_PI / 2);
	}
	if (compare_doubles(orientation[1], 0))
		return (get_x_y_rotation(orientation));
	else
		return (get_z_x_rotation(orientation));
}
