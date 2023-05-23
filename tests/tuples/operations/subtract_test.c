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

MU_TEST(test_subtracting_colors)
{
	t_tuple c1 = color(0.9, 0.6, 0.75);
	t_tuple c2 = color(0.7, 0.1, 0.25);
	t_tuple expected = color(0.2, 0.5, 0.5);
	t_tuple result = subtract(c1, c2);

	mu_assert(
		compare_tuples(result, expected),
		"(0.9, 0.6, 0.75) - (0.7, 0.1, 0.25) should be (0.2, 0.5, 0.5)"
	);

	free(c1);
	free(c2);
	free(expected);
	free(result);
}

MU_TEST(test_should_return_a_vector_when_subtract_two_vectors)
{
	t_tuple	v1 = vector(3, 2, 1);
	t_tuple	v2 = vector(5, 6, 7);
	t_tuple	expected = vector(-2, -4, -6);
	t_tuple	result = subtract(v1, v2);

	mu_assert(
		compare_tuples(result, expected),
		"subtraction of vector (3, 2, 1) and (5, 6, 7) should return the vector (-2, -4, -6)"
	);

	free(v1);
	free(v2);
	free(result);
	free(expected);
}

MU_TEST_SUITE(test_tuples_subtract)
{
	MU_RUN_TEST(test_should_return_a_vector_when_subtract_two_points);
	MU_RUN_TEST(test_should_return_a_point_when_subtract_point_from_vector);
	MU_RUN_TEST(test_should_return_a_vector_when_subtract_two_vectors);
	MU_RUN_TEST(test_subtracting_colors);

}
