#include <minirt.h>
#include <minunit.h>

MU_TEST(test_if_given_point_is_equal_to_multiplication_of_translated_matrix_with_another_point)
{
	float **transform = translation(5, -3, 2);
	t_tuple p = point(-3, 4, 5);
	t_tuple expected = point(2, 1, 7);
	t_tuple result = multiply_matrix_with_tuple(transform, p);
	mu_assert(compare_tuples(expected, result), "result should be 2, 1, 7");

	free(p);
	free(result);
	free(expected);
	free_matrix(transform);
}

MU_TEST(test_if_given_point_is_equal_to_multiplication_of_the_inverse_of_translated_matrix_with_another_point)
{
	float **transform = translation(5, -3, 2);
	float **inv = inverse(transform);
	t_tuple p = point(-3, 4, 5);
	t_tuple expected = point(-8, 7, 3);
	t_tuple result = multiply_matrix_with_tuple(inv, p);
	mu_check(compare_tuples(expected, result));
	free(expected);
	free(result);
	free(p);
	free_matrix(transform);
	free_matrix(inv);
}

MU_TEST(test_to_ensure_that_translation_does_not_affect_vectors)
{
	float **transform = translation(5, -3, 2);
	t_tuple v = vector(-3, 4, 5);
	t_tuple expected = v;
	t_tuple result = multiply_matrix_with_tuple(transform, v);
	mu_check(compare_tuples(expected, result));
	free(v);
	free(result);
	free_matrix(transform);
}

MU_TEST_SUITE(test_translation_matrix)
{
	MU_RUN_TEST(test_if_given_point_is_equal_to_multiplication_of_translated_matrix_with_another_point);
	MU_RUN_TEST(test_if_given_point_is_equal_to_multiplication_of_the_inverse_of_translated_matrix_with_another_point);
	MU_RUN_TEST(test_to_ensure_that_translation_does_not_affect_vectors);
}
