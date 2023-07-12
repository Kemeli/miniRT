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

t_world	*default_world(void)
{
	t_world			*world;
	t_material		*mat;
	t_sphere		*s;
	t_node			*n;
	t_list			*l;
	t_tuple			p;
	t_tuple			c;
	t_point_light	*light;

	p = point(-10, 10, -10);
	c = color(1, 1, 1);
	light = point_light(p, c);
	world = create_world();
	world->light = light;
	((t_node*)world->head->content)->object = ft_calloc(1, sizeof(t_object));
	((t_node*)world->head->content)->object->sphere = create_sphere();
	n = ft_calloc(1, sizeof(t_node));
	s = create_sphere();
	free_matrix(s->transform);
	s->transform = scaling(0.5, 0.5, 0.5);
	n->object = ft_calloc(1, sizeof(t_object));
	n->object->sphere = s;
	l = ft_lstnew(n);
	ft_lstadd_back(&(world->head), l);
	mat = material();
	free(mat->color);
	mat->color = color(0.8, 1.0, 0.6);
	mat->diffuse = 0.7;
	mat->specular = 0.2;
	((t_node*)world->head->content)->object->sphere->change_my_material(
		((t_node*)world->head->content)->object->sphere, mat);
	return (world);
}
