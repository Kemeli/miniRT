#include <minirt.h>

void	set_transform(t_object *o, t_matrix transform)
{
	free_matrix(o->transform);
	o->transform = transform;
	// free_matrix(o->inverse);
	o->inverse = inverse(o->transform);
	o->transpose_inverse = transpose_matrix(o->inverse);
	// t_matrix	transform;

	// transform = (*obj)->transform;
	// (*obj)->transform = multiply_matrix(transform, translation);
	// free_matrix(transform);
	int i = 0;
	int j = 0;
	while(o->inverse[i])
	{
		j = 0;
		while(o->inverse[i][j])
		{
			printf("%f ", o->inverse[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
