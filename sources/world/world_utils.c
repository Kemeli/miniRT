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
	if (world->head)
		free_objects_list(world->head);
	if(world->light)
	{
		free(world->light->intensity);
		free(world->light);
	}
	if(world->ambient)
		free(world->ambient);
	free(world);
	world = NULL;
}
