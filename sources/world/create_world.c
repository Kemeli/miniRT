#include <minirt.h>

t_world	*create_world(void)
{
	t_world	*world;

	world = ft_calloc(1, sizeof(t_world));
	world->head = ft_calloc(1, sizeof(t_node));
	world->head->object = NULL;
	world->light = NULL;
	return (world);
}

// t_world	*default_world(void)
// {
// 	t_world			*world;
// 	t_material		*mat;
// 	t_point_light	*light;

// 	world = create_world();
// 	world->head->object->sphere = create_sphere();
// 	world->head->next->object->sphere = create_sphere();

// 	mat = material();
// 	free(mat->color);
// 	mat->color = color(0.8, 1.0, 0.6);
// 	mat->diffuse = 0.7;
// 	mat->specular = 0.2;
// 	world->head->object->sphere->change_my_material(
// 		world->head->object->sphere, mat);

// 	free_matrix(s2->transform);
// 	s2->transform = scaling(0.5, 0.5, 0.5);
// 	return (world);
// }
