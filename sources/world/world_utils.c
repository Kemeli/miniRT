#include <minirt.h>

static void	free_content(t_object *obj)
{
	while(obj)
	{
		free_object(obj);
		obj = obj->next;
	}
}

void	free_world(t_world *world)
{
	free_content(world->head);
	free(world->light->intensity);
	free(world->light->position);
	free(world->light);
	free(world->head);
	free(world);
	world = NULL;
}
