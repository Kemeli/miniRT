#include <minirt.h>
#include <minunit.h>

MU_TEST(test_the_color_when_a_ray_misses)
{
	t_world	*w = default_world();
	t_tuple	ray_origin = point(0, 0, -5);
	t_tuple	ray_direction = vector(0, 1, 0);
	t_ray	*r = create_ray(ray_origin, ray_direction);

	t_tuple c = color_at(w, r);
	t_tuple expected = color(0, 0, 0);

	mu_check(compare_tuples(expected, c));

	free_world(w);
	free_ray(r);
	free(c);
	free(expected);
}

MU_TEST(test_the_color_when_a_ray_hits)
{
	t_world	*w = default_world();
	t_tuple	ray_origin = point(0, 0, -5);
	t_tuple	ray_direction = vector(0, 0, 1);
	t_ray	*r = create_ray(ray_origin, ray_direction);

	t_tuple expected = color(0.38066, 0.47583, 0.2855);
	t_tuple c = color_at(w, r);
	mu_check(compare_tuples(expected, c));

	free_world(w);
	free_ray(r);
	free(c);
	free(expected);
}

MU_TEST(test_the_color_with_an_intersection_behind_the_ray)
{
	t_world	*w = default_world();
	t_node	*outer = (t_node *)w->head->content;
	outer->object->material->ambient = color(1, 1, 1);
	t_node	*inner = (t_node *)w->head->next->content;
	inner->object->material->ambient = color(1, 1, 1);
	t_tuple	ray_origin = point(0, 0, 0.75);
	t_tuple	ray_direction = vector(0, 0, -1);
	t_ray	*r = create_ray(ray_origin, ray_direction);

	t_tuple c = color_at(w, r);
	t_tuple expected = inner->object->material->color;

	mu_check(compare_tuples(expected, c));

	free_world(w);
	free_ray(r);
	free(c);
}

MU_TEST_SUITE(test_color_at)
{
	MU_RUN_TEST(test_the_color_when_a_ray_misses);
	MU_RUN_TEST(test_the_color_when_a_ray_hits);
	MU_RUN_TEST(test_the_color_with_an_intersection_behind_the_ray);
}
