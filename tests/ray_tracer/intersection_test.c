#include <minirt.h>
#include <minunit.h>

//#############################################################################
// 					intersecting rays with spheres
//#############################################################################

MU_TEST(test_that_a_ray_intercepts_a_sphere_at_two_points)
{
	t_ray r = create_ray(point(0, 0, -5), vector(0, 0, 1));
	t_sphere s = create_sphere();
	t_intersect *xs = intersection(s, r);
	mu_assert_double_eq(4.0, xs->t1);
	mu_assert_double_eq(6.0, xs->t2);
	mu_assert_int_eq(2, xs->count);

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
	mu_assert_int_eq(1, xs->count);

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
	mu_assert_int_eq(0, xs->count);

	free (xs);
	free (r.direction);
	free (r.origin);
	free (s.center);
}

MU_TEST(test_that_a_ray_originates_inside_a_sphere)
{
	t_ray r = create_ray(point(0, 0, 0), vector(0, 0, 1));
	t_sphere s = create_sphere();
	t_intersect *xs = intersection(s, r);
	mu_assert_double_eq(-1.0, xs->t1);
	mu_assert_double_eq(1.0, xs->t2);
	mu_assert_int_eq(2, xs->count);

	free (xs);
	free (r.direction);
	free (r.origin);
	free (s.center);
}

MU_TEST(test_that_a_sphere_is_behind_a_ray)
{
	t_ray r = create_ray(point(0, 0, 5), vector(0, 0, 1));
	t_sphere s = create_sphere();
	t_intersect *xs = intersection(s, r);
	mu_assert_double_eq(-6.0, xs->t1);
	mu_assert_double_eq(-4.0, xs->t2);
	mu_assert_int_eq(2, xs->count);

	free (xs);
	free (r.direction);
	free (r.origin);
	free (s.center);
}

//#############################################################################
// 						trancking intersections
//#############################################################################

MU_TEST(test_that_an_intersection_encapsulates_t_and_object)
{
	t_sphere s = create_sphere();
	t_intersect *i = create_intersection(3.5, (void *)&s);
	mu_assert_double_eq(3.5, i->t1);
	mu_check(compare_pointers(&s, i->object));

	free (i);
	free (s.center);
}

// MU_TEST(test_that_a_collection_of_intersections_is_created)
// {
// 	t_intersect *list = create_intersection()
// }

//#############################################################################
//		 						test suite
//#############################################################################
MU_TEST_SUITE(test_interception_of_rays_and_spheres)
{
	MU_RUN_TEST(test_that_a_ray_intercepts_a_sphere_at_two_points);
	MU_RUN_TEST(test_that_a_ray_intercepts_a_sphere_at_a_tangent);
	MU_RUN_TEST(test_that_a_ray_misses_a_sphere);
	MU_RUN_TEST(test_that_a_ray_originates_inside_a_sphere);
	MU_RUN_TEST(test_that_a_sphere_is_behind_a_ray);

	MU_RUN_TEST(test_that_an_intersection_encapsulates_t_and_object);
	// MU_RUN_TEST(test_that_a_collection_of_intersections_is_created);

}
