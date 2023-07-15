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
	t_world		*w = default_world();

	((t_node *)w->head->content)->object->sphere->material->ambient = 1;
	((t_node *)w->head->next->content)->object->sphere->material->ambient = 1;

	t_tuple		ray_origin = point(0, 0, 0.75);
	t_tuple		ray_direction = vector(0, 0, -1);
	t_ray		*r = create_ray(ray_origin, ray_direction);

	t_tuple		c = color_at(w, r);

	// printf("\n\n c = %f %f %f\n\n", c[0], c[1], c[2]);
	// printf("\n\n material = %f %f %f\n\n",
	// 	((t_node *)w->head->next->content)->object->sphere->material->color[0],
	// 	((t_node *)w->head->next->content)->object->sphere->material->color[1],
	// 	((t_node *)w->head->next->content)->object->sphere->material->color[2]);

	mu_check(compare_tuples(((t_node *)w->head->next->content)->object->sphere->material->color, c));

	free(c);
	free_ray(r);
	free_world(w);
}

MU_TEST_SUITE(test_color_at)
{
	MU_RUN_TEST(test_the_color_when_a_ray_misses);
	MU_RUN_TEST(test_the_color_when_a_ray_hits);
	MU_RUN_TEST(test_the_color_with_an_intersection_behind_the_ray);
}
