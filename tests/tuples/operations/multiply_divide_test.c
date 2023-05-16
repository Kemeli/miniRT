#include <minunit.h>
#include <minirt.h>

MU_TEST(test_multiplication)
{
	float	times_to_multiply = 3.5;
	t_tuple	tuple_a = tuple(1, -2, 3, -4);
	t_tuple	expected = tuple(3.5, -7, 10.5, -14);
	t_tuple	result = scalar_multiplication(tuple_a, times_to_multiply);

	mu_assert(
		compare_tuples(expected, result), 
		"multiplication of tuple_a with 3.5 should be (3.5, -7, 10.5, -14)"
	);
}

MU_TEST_SUITE(test_multiply_divide)
{
	MU_RUN_TEST(test_multiplication);
}
