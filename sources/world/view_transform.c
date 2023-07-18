#include <minirt.h>

t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		sub;
	t_tuple		forward;
	t_tuple		normal_up;
	t_tuple		left;
	t_tuple		true_up;
	t_tuple		neg;
	t_matrix	orientation;
	t_matrix	transl;
	t_matrix	mult;

	orientation = matrix(4);
	sub = subtract(from, to);
	forward = normalize(sub);
	normal_up = normalize(up);
	left = cross(forward, normal_up);
	true_up = cross(left, forward);
	orientation[0][0] = left[0];
	orientation[0][1] = left[1];
	orientation[0][2] = left[2];
	orientation[1][0] = true_up[0];
	orientation[1][1] = true_up[1];
	orientation[1][2] = true_up[2];
	orientation[2][0] = -forward[0];
	orientation[2][1] = -forward[1];
	orientation[2][2] = -forward[2];
	orientation[3][3] = 1;
	neg = negative(from);
	transl = translation(neg[0], neg[1], neg[2]);
	mult = multiply_matrix(orientation, transl);
	return (mult);

}
