#include <minirt.h>
#include <minunit.h>

MU_TEST(test_to_ensure_scaling_matrix_multiplied_to_a_point_has_expected_point_values)
{
	double **transform = scaling(2, 3, 4);
	t_tuple p = point(-4, 6, 8);
	t_tuple expected = point(-8, 18, 32);
	t_tuple result = multiply_matrix_with_tuple(transform, p);
	mu_assert(compare_tuples(expected, result), "result should be -8, 18, 32");

	free(p);
	free(expected);
	free(result);
	free_matrix(transform);
}

MU_TEST(test_to_ensure_scaling_matrix_multiplied_to_a_vector_changes_its_length)
{
	double **transform = scaling(2, 3, 4);
	t_tuple v = vector(-4, 6, 8);
	t_tuple expected = vector(-8, 18, 32);
	t_tuple result = multiply_matrix_with_tuple(transform, v);
	mu_assert(compare_tuples(expected, result), "result should be -8, 18, 32");
	free (v);
	free(expected);
	free(result);
	free_matrix(transform);
}

MU_TEST(test_that_multiplying_a_tuple_by_the_inverse_of_a_scaling_matrix_scales_in_the_opposite_way)
{
	double **transform = scaling(2, 3, 4);
	double **inv = inverse(transform);
	t_tuple v = vector(-4, 6, 8);
	t_tuple expected = vector(-2, 2, 2);
	t_tuple result = multiply_matrix_with_tuple(inv, v);
	mu_assert(compare_tuples(expected, result), "result should be -2, 2, 2");

	free(v);
	free(expected);
	free(result);
	free_matrix(transform);
	free_matrix(inv);
}

MU_TEST(test_that_reflection_is_scaling_by_a_negative_value)
{
	double **transform = scaling(-1, 1, 1);
	t_tuple p = point(2, 3, 4);
	t_tuple expected = point(-2, 3, 4);
	t_tuple result = multiply_matrix_with_tuple(transform, p);
	mu_assert(compare_tuples(expected, result), "result should be -2, 3, 4");

	free(p);
	free(expected);
	free(result);
	free_matrix(transform);
}

MU_TEST_SUITE(test_scaling_by_multiplication)
{
	MU_RUN_TEST(test_to_ensure_scaling_matrix_multiplied_to_a_point_has_expected_point_values);
	MU_RUN_TEST(test_to_ensure_scaling_matrix_multiplied_to_a_vector_changes_its_length);
	MU_RUN_TEST(test_that_multiplying_a_tuple_by_the_inverse_of_a_scaling_matrix_scales_in_the_opposite_way);
	MU_RUN_TEST(test_that_reflection_is_scaling_by_a_negative_value);
}
