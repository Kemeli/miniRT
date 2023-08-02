#include <minirt.h>

void	free_object(t_object *object)
{
	free(object->material->color);
	free(object->material);
	free_matrix(object->transform);
	if (object->saved_ray)
		free_ray(object->saved_ray);
	if (object->shape == 's')
		free_sphere(object->sphere);
// 	else if(object->plane)
// 		free_plane(object->plane);
// 	else if(object->cylinder)
// 		free_cylinder(object->cylinder);
	free(object);
}
