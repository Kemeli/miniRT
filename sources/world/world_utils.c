#include <minirt.h>

static void	free_content(void *node)
{
	free_object(((t_node *)node)->object);
	free((t_node *)node);
}

void	free_world(t_world *world)
{
	ft_lstclear(&(world->head), free_content);
	free(world->light->intensity);
	free(world->light->position);
	free(world->light);
	free(world->head);
	free(world);
}
