#include <minirt.h>

float	**rotation_x(float radian)
{
	float	**rotation_matrix;

	rotation_matrix = identity_matrix(4);
	rotation_matrix[1][1] = cos(radian);
	rotation_matrix[1][2] = -sin(radian);
	rotation_matrix[2][1] = sin(radian);
	rotation_matrix[2][2] = sin(radian);
	return (rotation_matrix);
}

float	**rotation_y(float radian)
{
	float	**rotation_matrix;

	rotation_matrix = identity_matrix(4);
	rotation_matrix[0][0] = cos(radian);
	rotation_matrix[0][2] = sin(radian);
	rotation_matrix[2][0] = -sin(radian);
	rotation_matrix[2][2] = cos(radian);
	return (rotation_matrix);
}

float	**rotation_z(float radian)
{
	float	**rotation_matrix;

	rotation_matrix = identity_matrix(4);
	rotation_matrix[0][0] = cos(radian);
	rotation_matrix[0][1] = -sin(radian);
	rotation_matrix[1][0] = sin(radian);
	rotation_matrix[1][1] = cos(radian);
	return (rotation_matrix);
}
