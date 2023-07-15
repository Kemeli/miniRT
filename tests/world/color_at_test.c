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

MU_TEST_SUITE(test_color_at)
{
	MU_RUN_TEST(test_the_color_when_a_ray_misses);
}
