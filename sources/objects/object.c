#include <minirt.h>

t_object	*create_object(char shape)
{
	t_object	*object;

	object = ft_calloc(1, sizeof(t_object));
	object->shape = shape;
	object->transform = identity_matrix(4);
	object->material = material();
	object->change_my_material = change_material;
	// object->saved_ray = ft_calloc(1, sizeof(t_ray));
	// object->saved_ray = NULL;
	if (shape == 's')
		object->sphere = create_sphere();
	if (shape == 'p')
		object->plane = create_plane();
	// if (shape == 'c')
	// 	object->sphere = create_sphere();
	return (object);
}

void	change_material(t_object *obj, t_material *m)
{
	free(obj->material->color);
	free(obj->material);
	obj->material = m;
}
