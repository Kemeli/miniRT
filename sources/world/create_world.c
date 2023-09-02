#include <minirt.h>

t_world	*create_world(void)
{
	t_world	*world;

	world = ft_calloc(1, sizeof(t_world));
	world->head = ft_calloc(1, sizeof(t_object));
	world->head = (void *)ft_calloc(1, sizeof(t_node));
	world->head = NULL;
	world->light = NULL;
	return (world);
}

static t_object	*objects_list(t_object *head)
{
	t_node		*next_node;
	t_material	*mat;

	head = create_object('s');
	next_node = ft_calloc(1, sizeof(t_node));
	next_node->object = create_object('s');
	free_matrix(next_node->object->transform);
	next_node->object->transform = scaling(0.5, 0.5, 0.5);
	append_object(&head, &next_node->object);
	mat = material();
	free(mat->color);
	mat->color = color(0.8, 1.0, 0.6);
	mat->diffuse = 0.7;
	mat->specular = 0.2;
	head->change_my_material(head, mat);
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
