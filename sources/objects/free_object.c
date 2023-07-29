#include <minirt.h>

void	free_object(t_object *object)
{
	if (object->sphere)
		free_sphere(object->sphere);
// 	else if(object->plane)
// 		free_plane(object->plane);
// 	else if(object->cylinder)
// 		free_cylinder(object->cylinder);
	free(object);
}
