#include <minunit.h>
#include <minirt.h>

MU_TEST(test_should_return_a_vector_when_subtract_two_points)
{
	t_tuple	a = point(3, 2, 1);
	t_tuple	b = point(5, 6, 7);
	t_tuple	result = subtract(a, b);
	t_tuple	expected = vector(-2, -4, -6);

	mu_assert(
		compare_tuples(result, expected), 
		"subtraction of point (3, 2, 1) and (5, 6, 7) should return the vector (-2, -4, -6)"
	);

	free(a);
	free(b);
	free(result);
	free(expected);
}

MU_TEST(test_should_return_a_point_when_subtract_point_from_vector)
{
	t_tuple	p = point(3, 2, 1);
	t_tuple	v = vector(5, 6, 7);
	t_tuple	expected = point(-2, -4, -6);
	t_tuple	result = subtract(p, v);

	mu_assert(
		compare_tuples(result, expected), 
		"subtraction of point (3, 2, 1) and vector (5, 6, 7) should return the point (-2, -4, -6)"
	);

	free(p);
	free(v);
	free(result);
	free(expected);
}

MU_TEST_SUITE(test_tuples_subtract)
{
	MU_RUN_TEST(test_should_return_a_vector_when_subtract_two_points);
	MU_RUN_TEST(test_should_return_a_point_when_subtract_point_from_vector);
}
