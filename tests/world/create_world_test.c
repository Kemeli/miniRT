#include <minirt.h>
#include <minunit.h>

MU_TEST(test_create_world)
{
	t_world	*world;

	world = create_world();
	mu_check(((t_node*)world->head->content)->object == NULL);
	mu_check(world->light == NULL);

	free(world->head->content);
	free(world->head);
	free(world);
}

MU_TEST(test_default_world)
{
	t_tuple p = point(-10, 10, -10);
	t_tuple c = color(1, 1, 1);
	t_point_light *light = point_light(p, c);

	t_object *o1 = create_object('s');
	free(o1->material->color);
	o1->material->color = color(0.8, 1.0, 0.6);
	o1->material->diffuse = 0.7;
	o1->material->specular = 0.2;

	t_object *o2 = create_object('s');
	free_matrix(o2->transform);
	o2->transform = scaling(0.5, 0.5, 0.5);

	t_world *world = default_world();
	mu_check(compare_tuples(world->light->position, light->position));
	mu_check(compare_tuples(world->light->intensity, light->intensity));

	mu_check(compare_tuples(((t_node*)world->head->content)->object->material->color, o1->material->color));
	mu_check(compare_floats(((t_node*)world->head->content)->object->material->diffuse, o1->material->diffuse));
	mu_check(compare_floats(((t_node*)world->head->content)->object->material->specular, o1->material->specular));

	mu_check(compare_matrices(((t_node*)world->head->next->content)->object->transform, o2->transform));

	free_object(o1);
	free_object(o2);
	free(light->intensity);
	free(light->position);
	free(light);
	free_world(world);
}

MU_TEST(test_Intersect_a_world_with_a_ray)
{
	t_world	*world = default_world();
	t_tuple	p = point(0, 0, -5);
	t_tuple	v = vector(0, 0, 1);
	t_ray	*r = create_ray(p, v);
	t_intersect	*xs;

	xs = intersect_world(world, r);
	mu_check(4 == xs->count);
	mu_check(4 == xs->head->t);
	mu_check(4.5 == xs->head->next->t);
	mu_check(5.5 == xs->head->next->next->t);
	mu_check(6 == xs->head->next->next->next->t);

	free_world(world);
	free_intersections(xs);
	free_ray(r);
}

MU_TEST_SUITE(test_build_world)
{
	MU_RUN_TEST(test_create_world);
	MU_RUN_TEST(test_default_world);
	MU_RUN_TEST(test_Intersect_a_world_with_a_ray);
}
