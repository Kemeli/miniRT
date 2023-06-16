#include <minirt.h>
#include <minunit.h>

MU_TEST(test_that_a_ray_intercepts_a_sphere_at_two_points)
{
	t_ray r = create_ray(point(0, 0, -5), vector(0, 0, 1));
	t_sphere s = create_sphere();
	t_intersect *xs = intersection(s, r);
	mu_assert_double_eq(4.0, xs->t1);
	mu_assert_double_eq(6.0, xs->t2);

	free (xs);
	free (r.direction);
	free (r.origin);
	free (s.center);
}

MU_TEST(test_that_a_ray_intercepts_a_sphere_at_a_tangent)
{
	t_ray r = create_ray(point(0, 1, -5), vector(0, 0, 1));
	t_sphere s = create_sphere();
	t_intersect *xs = intersection(s, r);
	mu_assert_double_eq(5.0, xs->t1);
	mu_assert_double_eq(5.0, xs->t2);

	free (xs);
	free (r.direction);
	free (r.origin);
	free (s.center);
}

MU_TEST(test_that_a_ray_misses_a_sphere)
{
	t_ray r = create_ray(point(0, 2, -5), vector(0, 0, 1));
	t_sphere s = create_sphere();
	t_intersect *xs = intersection(s, r);
	mu_assert_double_eq(0, xs->t1);
	mu_assert_double_eq(0, xs->t2);

	free (xs);
	free (r.direction);
	free (r.origin);
	free (s.center);
}

MU_TEST_SUITE(test_interception_of_rays_and_spheres)
{
	MU_RUN_TEST(test_that_a_ray_intercepts_a_sphere_at_two_points);
	MU_RUN_TEST(test_that_a_ray_intercepts_a_sphere_at_a_tangent);
	MU_RUN_TEST(test_that_a_ray_misses_a_sphere);
}
