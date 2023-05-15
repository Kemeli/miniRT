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

MU_TEST(test_sum_with_negated_vector_should_be_equal_to_subract_these_vectors)
{
	int	i = 0;

	t_tuple	v = vector(3.5, 10, 11);
	t_tuple	w = vector(5, 1, 0);
	t_tuple	minus_w = negative(w);
	t_tuple	expected = subtract(v, w);

	while (i < 3)
	{
		mu_assert_double_eq(expected[i], v[i] + minus_w[i]);
		i++;
	}
	
	free(v);
	free(w);
	free(minus_w);
	free(expected);
}

MU_TEST_SUITE(test_negating_tuples)
{
	MU_RUN_TEST(test_negated_vector_should_be_equal_to_null_vector_minus_the_vector);
	MU_RUN_TEST(test_sum_with_negated_vector_should_be_equal_to_subract_these_vectors);
}
