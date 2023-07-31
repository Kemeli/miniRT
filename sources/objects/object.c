#include <minirt.h>

t_object	*create_object(char shape)
{
	t_object	*object;

	object = ft_calloc(1, sizeof(t_object));
	object->shape = shape;
	if (shape == 's')
		object->sphere = create_sphere();
	// if (shape == 'p')
	// 	object->sphere = create_sphere();
	// if (shape == 'c')
	// 	object->sphere = create_sphere();
	return (object);
}
