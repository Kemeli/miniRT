#include <minirt.h>
#include <minunit.h>

MU_TEST(test_creating_and_quering_a_ray)
{
	t_tuple origin = point(1, 2, 3);
	t_tuple direction = vector(4, 5, 6);
	t_ray *r = create_ray(origin, direction);
	mu_check(compare_tuples(r->origin, origin));
	mu_check(compare_tuples(r->direction, direction));

	free(origin);
	free(direction);
	free(r);
}

MU_TEST(test_computing_a_point_from_a_distance)
{
	t_tuple p = point(2, 3, 4);
	t_tuple v = vector(1, 0, 0);
	t_ray *r = create_ray(p, v);
	t_tuple result1 = get_point_position(r, 0);
	t_tuple expected1 = point(2, 3, 4);
	t_tuple result2 = get_point_position(r, 1);
	t_tuple expected2 = point(3, 3, 4);
	t_tuple result3 = get_point_position(r, -1);
	t_tuple expected3 = point(1, 3, 4);
	t_tuple result4 = get_point_position(r, 2.5);
	t_tuple expected4 = point(4.5, 3, 4);

	mu_check(compare_tuples(result1, expected1));
	mu_check(compare_tuples(result2, expected2));
	mu_check(compare_tuples(result3, expected3));
	mu_check(compare_tuples(result4, expected4));

	free(result1);
	free(result2);
	free(result3);
	free(result4);
	free(expected1);
	free(expected2);
	free(expected3);
	free(expected4);
	free(p);
	free(v);
	free(r);
}

MU_TEST_SUITE(test_create_ray)
{
	MU_RUN_TEST(test_creating_and_quering_a_ray);
	MU_RUN_TEST(test_computing_a_point_from_a_distance);
}



