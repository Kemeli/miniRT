#include <minirt.h>

char	compare_floats(float n1, float n2)
{
	float	epsilon;

	epsilon = 0.000001;
	if (fabs(n1 - n2) <= epsilon)
		return (1);
	return (0);
}
