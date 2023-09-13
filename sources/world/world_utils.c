#include <minirt.h>

void	free_objects_list(t_object *obj)
{
	t_object	*next;

	while (obj)
	{
		next = obj->next;
		free_object(obj);
		obj = next;
	}
}

void	free_world(t_world *world)
{
	free_objects_list(world->head);
	free(world->light->intensity);
	// free(world->light->position);
	free(world->light);
	free(world->ambient);
	// free(world->head);
	free(world);
	world = NULL;
}
