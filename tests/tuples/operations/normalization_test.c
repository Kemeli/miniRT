#include <minunit.h>
#include <minirt.h>

MU_TEST(test_vector_4_0_0_normalized_should_be_vector_1_0_0)
{
	t_tuple	v = vector(4, 0, 0);
	t_tuple	expected = vector(1, 0, 0);
	t_tuple	result = normalize(v);

	mu_assert(
		compare_tuples(result, expected), "msg"
	);
	free(v);
	free(expected);
	free(result);
}

MU_TEST(test_vector_1_2_3_normalized_should_be_vector_026726_053452_080178)
{
	t_tuple	v = vector(1, 2, 3);
	t_tuple	expected = vector(1 / sqrt(14), 2 / sqrt(14), 3 / sqrt(14));
	t_tuple	result = normalize(v);

	mu_assert(
		compare_tuples(result, expected), "msg"
	);
	free(v);
	free(expected);
	free(result);
}

MU_TEST(test_magnitude_of_a_normalized_vector_should_be_1)
{
	t_tuple	v = vector(1, 2, 3);
	t_tuple	norm = normalize(v);
	double	expected = 1;
	double	result = magnitude(norm);
	mu_assert_double_eq(result, expected);
	free(v);
	free(norm);
}

MU_TEST_SUITE(test_tuples_normalization)
{
	MU_RUN_TEST(test_vector_4_0_0_normalized_should_be_vector_1_0_0);
	MU_RUN_TEST(test_vector_1_2_3_normalized_should_be_vector_026726_053452_080178);
	MU_RUN_TEST(test_magnitude_of_a_normalized_vector_should_be_1);
}
