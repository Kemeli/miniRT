#include <minirt.h>

t_world	*create_world(void)
{
	t_world	*world;

	world = ft_calloc(1, sizeof(t_world));
	world->head = ft_calloc(1, sizeof(t_list));
	world->head->content = (void *)ft_calloc(1, sizeof(t_node));
	((t_node *)world->head->content)->object = NULL;
	world->light = NULL;
	return (world);
}

static t_list	*objects_list(t_list *head)
{
	t_node		*next_node;
	t_material	*mat;

	((t_node*)head->content)->object = ft_calloc(1, sizeof(t_object));
	((t_node*)head->content)->object->sphere = create_sphere();
	next_node = ft_calloc(1, sizeof(t_node));
	next_node->object = ft_calloc(1, sizeof(t_object));
	next_node->object->sphere = create_sphere();
	free_matrix(next_node->object->sphere->transform);
	next_node->object->sphere->transform = scaling(0.5, 0.5, 0.5);
	ft_lstadd_back(&head, ft_lstnew(next_node));
	mat = material();
	free(mat->color);
	mat->color = color(0.8, 1.0, 0.6);
	mat->diffuse = 0.7;
	mat->specular = 0.2;
	((t_node*)head->content)->object->sphere->change_my_material(
		((t_node*)head->content)->object->sphere, mat);
	return (head);
}

t_world	*default_world(void)
{
	t_world			*world;
	t_tuple			p;
	t_tuple			c;
	t_point_light	*light;

	p = point(-10, 10, -10);
	c = color(1, 1, 1);
	light = point_light(p, c);
	world = create_world();
	world->light = light;
	world->head = objects_list(world->head);
	return (world);
}
