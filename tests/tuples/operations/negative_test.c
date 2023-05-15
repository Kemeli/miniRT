#include <minunit.h>
#include <minirt.h>

MU_TEST(test_negated_vector_should_be_equal_to_null_vector_minus_the_vector)
{
	t_tuple	v_null = vector(0, 0, 0);
	t_tuple	v = vector(1, -2, 3);
	t_tuple	expected = subtract(v_null, v);
	t_tuple	result = negative(v);

	mu_assert(
		compare_tuples(expected, result),
		"The vector V should be equal to the operation (0, 0, 0) - (1, -2, 3)"
	);

	free(v_null);
	free(v);
	free(expected);
	free(result);
}

MU_TEST_SUITE(test_negating_tuples)
{
	MU_RUN_TEST(test_negated_vector_should_be_equal_to_null_vector_minus_the_vector);
}
