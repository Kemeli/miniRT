#include <minunit.h>
#include <minirt.h>

MU_TEST(test_multiplication)
{
	double	times_to_multiply = 3.5;
	t_tuple	tuple_a = tuple(1, -2, 3, -4);
	t_tuple	expected = tuple(3.5, -7, 10.5, -14);
	t_tuple	result = multiply_tuple_by_scalar(tuple_a, times_to_multiply);

	mu_assert(
		compare_tuples(expected, result),
		"multiplication of tuple_a with 3.5 should be (3.5, -7, 10.5, -14)"
	);
	free(tuple_a);
	free(expected);
	free(result);
}

MU_TEST(test_multiplication_by_decimal)
{
	double	times_to_multiply = 0.5;
	t_tuple	tuple_a = tuple(1, -2, 3, -4);
	t_tuple	expected = tuple(0.5, -1, 1.5, -2);
	t_tuple	result = multiply_tuple_by_scalar(tuple_a, times_to_multiply);

	mu_assert(
		compare_tuples(expected, result),
		"multiplication of tuple_a with 0.5 should be (0.5, -1, 1.5, -2)"
	);
	free(tuple_a);
	free(expected);
	free(result);
}

MU_TEST(test_division)
{
	double	times_to_divide = 2;
	t_tuple	tuple_a = tuple(1, -2, 3, -4);
	t_tuple	expected = tuple(0.5, -1, 1.5, -2);
	t_tuple	result = scalar_division(tuple_a, times_to_divide);

	mu_assert(
		compare_tuples(expected, result),
		"division of tuple_a with 2 should be (0.5, -1, 1.5, -2)"
	);
	free(tuple_a);
	free(expected);
	free(result);
}

MU_TEST(test_multiplying_color_by_scalar)
{
	t_tuple c1 = color(0.2, 0.3, 0.4);
	double   scalar = 2;
	t_tuple expected = color(0.4, 0.6, 0.8);
	t_tuple result = multiply_tuple_by_scalar(c1, scalar);

	mu_assert(
		compare_tuples(result, expected),
		"(0.2, 0.3, 0.4) * 2 should be (0.4, 0.6, 0.8)"
	);

	free(c1);
	free(expected);
	free(result);
}

MU_TEST_SUITE(test_multiply_divide)
{
	MU_RUN_TEST(test_multiplication);
	MU_RUN_TEST(test_multiplication_by_decimal);
	MU_RUN_TEST(test_division);
	MU_RUN_TEST(test_multiplying_color_by_scalar);

}

