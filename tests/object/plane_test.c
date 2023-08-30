#include <minirt.h>
#include <minunit.h>

MU_TEST(test_the_normal_of_a_plane_is_constant_everywhere)
{
	t_object *o = create_object('p');

	t_tuple p1 = point(0, 0, 0);
	t_tuple p2 = point(10, 0, -10);
	t_tuple p3 = point(-5, 0, 150);

	t_tuple n1 = local_normal_at(o, p1);
	t_tuple n2 = local_normal_at(o, p2);
	t_tuple n3 = local_normal_at(o, p3);

	t_tuple expected = vector(0, 1, 0);

	mu_check(compare_tuples(n1, expected));
	mu_check(compare_tuples(n2, expected));
	mu_check(compare_tuples(n3, expected));


	free_object(o);
	free(p1);
	free(p2);
	free(p3);
	free(n1);
	free(n2);
	free(n3);
	free(expected);
}

MU_TEST(test_intersect_with_a_ray_parallel_to_the_plane)
{
	t_object *o = create_object('p');

	t_tuple origin = point(0, 10, 0);
	t_tuple direction = vector(0, 0, 1);
	t_ray *r = create_ray(origin, direction);

	t_intersect *xs = intersect(&o, r);

	mu_check(xs->count == 0);

	free_object(o);
	free_ray(r);
	free_intersections(xs);
}

MU_TEST(test_intersect_with_a_coplanar_ray)
{
	t_object *o = create_object('p');

	t_tuple origin = point(0, 0, 0);
	t_tuple direction = vector(0, 0, 1);
	t_ray *r = create_ray(origin, direction);

	t_intersect *xs = intersect(&o, r);

	mu_check(xs->count == 0);

	free_object(o);
	free_ray(r);
	free_intersections(xs);
}

MU_TEST(test_a_ray_intersecting_a_plane_from_above)
{
	t_object *o = create_object('p');

	t_tuple origin = point(0, 1, 0);
	t_tuple direction = vector(0, -1, 0);
	t_ray *r = create_ray(origin, direction);

	t_intersect *xs = intersect(&o, r);

	mu_check(xs->count == 1);
	mu_check(compare_floats(xs->head->t, 1));
	mu_check(compare_pointers(xs->head->object, o));

	free_object(o);
	free_ray(r);
	free_intersections(xs);
}

MU_TEST(test_a_ray_intersecting_a_plane_from_below)
{
	t_object *o = create_object('p');

	t_tuple origin = point(0, -1, 0);
	t_tuple direction = vector(0, 1, 0);
	t_ray *r = create_ray(origin, direction);

	t_intersect *xs = intersect(&o, r);

	mu_check(xs->count == 1);
	mu_check(compare_floats(xs->head->t, 1));
	mu_check(compare_pointers(xs->head->object, o));

	free_object(o);
	free_ray(r);
	free_intersections(xs);
}

MU_TEST_SUITE(test_plane)
{
	MU_RUN_TEST(test_the_normal_of_a_plane_is_constant_everywhere);
	MU_RUN_TEST(test_intersect_with_a_ray_parallel_to_the_plane);
	MU_RUN_TEST(test_intersect_with_a_coplanar_ray);
	MU_RUN_TEST(test_a_ray_intersecting_a_plane_from_above);
	MU_RUN_TEST(test_a_ray_intersecting_a_plane_from_below);
}
