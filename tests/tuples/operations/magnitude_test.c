#include <minunit.h>
#include <minirt.h>

MU_TEST(test_magnitude_of_a_vector_1_0_0_should_be_equal_to_1)
{
	t_tuple	v = vector(1, 0, 0);
	double	expected = 1.0;
	double	result = magnitude(v);

	mu_assert_double_eq(result, expected);

	free(v);
}

MU_TEST(test_magnitude_of_a_vector_0_1_0_should_be_equal_to_1)
{
	t_tuple	v = vector(0, 1, 0);
	double	expected = 1.0;
	double	result = magnitude(v);

	mu_assert_double_eq(result, expected);

	free(v);
}

MU_TEST(test_magnitude_of_a_vector_0_0_1_should_be_equal_to_1)
{
	t_tuple	v = vector(0, 0, 1);
	double	expected = 1.0;
	double	result = magnitude(v);

	mu_assert_double_eq(result, expected);

	free(v);
}

MU_TEST(test_magnitude_of_a_vector_1_2_3_should_be_equal_to_sqrt_14)
{
	t_tuple	v = vector(1, 2, 3);
	double	expected = sqrt(14);
	double	result = magnitude(v);

	mu_assert_double_eq(result, expected);

	free(v);

	v = vector(-1, -2, -3);
	expected = sqrt(14);
	result = magnitude(v);

	mu_assert_double_eq(result, expected);

	free(v);
}

MU_TEST_SUITE(test_magnitude)
{
	MU_RUN_TEST(test_magnitude_of_a_vector_1_0_0_should_be_equal_to_1);
	MU_RUN_TEST(test_magnitude_of_a_vector_0_1_0_should_be_equal_to_1);
	MU_RUN_TEST(test_magnitude_of_a_vector_0_0_1_should_be_equal_to_1);
	MU_RUN_TEST(test_magnitude_of_a_vector_1_2_3_should_be_equal_to_sqrt_14);
}
