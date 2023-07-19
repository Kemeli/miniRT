#include <minunit.h>
#include <minirt.h>

MU_TEST(test_constructing_a_ray_through_the_center_of_the_canvas)
{
	t_camera	*c = camera(201, 101, M_PI / 2);
	t_ray		*r = ray_for_pixel(c, 100, 50);

	t_tuple		p = point(0, 0, 0);
	t_tuple		v = vector(0, 0, -1);

	mu_check(compare_tuples(r->origin, p));
	mu_check(compare_tuples(r->direction, v));

	free_camera(c);
	free_ray(r);
	free(p);
	free(v);
}

MU_TEST_SUITE(test_ray_for_pixel)
{
	MU_RUN_TEST(test_constructing_a_ray_through_the_center_of_the_canvas);
}

