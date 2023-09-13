#include <minirt.h>

void	free_plane(t_plane *plane)
{
	free(plane->point);
	free(plane->orientation);
	free(plane);
}

void	free_object(t_object *object)
{
	free(object->material->color);
	free(object->material);
	// free_matrix(object->transform);
	// if (object->saved_ray)
	// 	free_ray(object->saved_ray);
	if (object->shape == 's')
		free_sphere(object->sphere);
	else if (object->shape == 'p')
		free_plane(object->plane);
	else if(object->shape == 'c')
		free(object->cylinder);
	// free(object);
}
