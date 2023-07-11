#include <minirt.h>
#include <minunit.h>

void	free_world(t_world *world)
{
	free(world->head->object->sphere->material->color);
	free(world->head->object->sphere->material);
	free(world->head->object->sphere);
	free(world->head->object);
	free(world->light->intensity);
	free(world->light->position);
	free(world->light);
	free(world);
}

MU_TEST(test_create_world)
{
	t_world	*world;

	world = create_world();
	mu_check(world->head->object == NULL);
	mu_check(world->light == NULL);

	free(world);
}

// MU_TEST(test_default_world)
// {
// 	t_tuple p = point(-10, 10, -10);
// 	t_tuple c = color(1, 1, 1);
// 	t_point_light *light = point_light(p, c);

// 	t_sphere *s1 = create_sphere();
// 	s1->material->color = color(0.8, 1.0, 0.6);
// 	s1->material->diffuse = 0.7;
// 	s1->material->specular = 0.2;

// 	t_sphere *s2 = create_sphere();
// 	s2->transform = scaling(0.5, 0.5, 0.5);

// 	t_world *world = default_world();
// 	mu_check(compare_tuples(world->light->position, light->position));
// 	mu_check(compare_tuples(world->light->intensity, light->intensity));

// 	mu_check(compare_tuples(world->head->object->sphere->material->color, s1->material->color));
// 	mu_check(compare_floats(world->head->object->sphere->material->diffuse, s1->material->diffuse));
// 	mu_check(compare_floats(world->head->object->sphere->material->specular, s1->material->specular));

// 	mu_check(compare_matrices(world->head->object->sphere->transform, s2->transform));

// 	free(light->intensity);
// 	free(light->position);
// 	free(light);

// 	free_sphere(s1);
// 	free_sphere(s2);

// 	free_world(world);
// }

MU_TEST_SUITE(test_build_world)
{
	MU_RUN_TEST(test_create_world);
	// MU_RUN_TEST(test_default_world);
}


