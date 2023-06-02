#include <minirt.h>
#include <minunit.h>
#include <stdio.h>

MU_TEST(test_if_a_matrix_is_invertible)
{
	float matrix_values[4][4] = {
	{6, 4, 4, 4},
	{5, 5, 7, 6},
	{4, -9, 3, -7},
	{9, 1, 7, -6 }
	};

	copy_size = 4;
	float **matrix_A = copy_matrix(matrix_values);
	float result = determinant(matrix_A);
	float expected = -2120;

	mu_assert_double_eq(result, expected);
	free_matrix(matrix_A);
}

MU_TEST(test_if_a_matrix_is_uninvertible)
{
	float matrix_values[4][4] = {
	{-4, 2, -2, -3},
	{9, 6, 2, 6},
	{0, -5, 1, -5},
	{0, 0, 0, 0}
	};

	copy_size = 4;
	float **matrix_A = copy_matrix(matrix_values);
	float result = determinant(matrix_A);
	float expected = 0;

	mu_assert_double_eq(result, expected);
	free_matrix(matrix_A);
}

MU_TEST(test_if_a_inverted_matrix_is_equal_to_a_received_matrix)
{
	float matrix_A_values[4][4] = {
		{-5, 2, 6, -8},
		{1, -5, 1, 8},
		{7, 7, -6, -7},
		{1, -3, 7, 4}
	};
	copy_size = 4;
	float **matrix_A = copy_matrix(matrix_A_values);
	float **matrix_inverse = inverse(matrix_A);
	mu_assert_double_eq(cofactor(matrix_A, 2, 3), -160);
	mu_assert_double_eq(matrix_inverse[3][2], -160.f / 532.f);
	mu_assert_double_eq(cofactor(matrix_A, 3, 2), 105);
	mu_assert_double_eq(matrix_inverse[2][3], 105.f / 532.f);
	float matrix_expected_values[4][4] = {
		{0.21805, 0.45113, 0.24060, -0.04511},
		{-0.80827, -1.45677, -0.44361, 0.52068},
		{-0.07895, -0.22368, -0.05263, 0.19737},
		{-0.52256, -0.81391, -0.30075, 0.30639}
	};
	float **matrix_expected = copy_matrix(matrix_expected_values);
	mu_check(compare_matrices(matrix_expected, matrix_inverse));

	free_matrix(matrix_A);
	free_matrix(matrix_expected);
	free_matrix(matrix_inverse);
}

MU_TEST(test_if_inverse_function_returns_correct_matrices_1)
{
	float	matrix_values[4][4] = {
		{8, -5, 9, 2},
		{7, 5, 6, 1},
		{-6, 0, 9, 6},
		{-3, 0, -9, -4}
	};
	float	expected_values[4][4] = {
		{-0.15385, -0.15385, -0.28205, -0.53846},
		{-0.07692, 0.12308, 0.02564, 0.03077},
		{0.35897, 0.35897, 0.43590, 0.92308},
		{-0.69231, -0.69231, -0.76923, -1.92308}
	};
	copy_size = 4;
	float	**matrix_A = copy_matrix(matrix_values);
	float	**expected_matrix = copy_matrix(expected_values);
	float	**inverse_A = inverse(matrix_A);

	mu_assert(
		compare_matrices(expected_matrix, inverse_A),
		"Inverse matrix does not have the expected values"
	);

	free_matrix(matrix_A);
	free_matrix(expected_matrix);
	free_matrix(inverse_A);
}

MU_TEST(test_if_inverse_function_returns_correct_matrices_2)
{
	float	matrix_values[4][4] = {
		{9, 3, 0, 9},
		{-5, -2, -6, -3},
		{-4, 9, 6, 4},
		{-7, 6, 6, 2}
	};
	float	expected_values[4][4] = {
		{-0.04074, -0.07778, 0.14444, -0.22222},
		{-0.07778, 0.03333, 0.36667, -0.33333},
		{-0.02901, -0.14630, -0.10926, 0.12963},
		{0.17778, 0.06667, -0.26667, 0.33333}
	};
	copy_size = 4;
	float	**matrix_A = copy_matrix(matrix_values);
	float	**expected_matrix = copy_matrix(expected_values);
	float	**inverse_A = inverse(matrix_A);

	mu_assert(
		compare_matrices(expected_matrix, inverse_A),
		"Inverse matrix does not have the expected values"
	);

	free_matrix(matrix_A);
	free_matrix(expected_matrix);
	free_matrix(inverse_A);
}

MU_TEST(test_if_multiplying_by_inverse_gets_back_to_original_matrix)
{
	float	matrix_A_values[4][4] = {
		{3, -9, 7, 3},
		{3, -8, 2, -9},
		{-4, 4, 4, 1},
		{-6, 5, -1, 1}
	};
	float	matrix_B_values[4][4] = {
		{8, 2, 2, 2},
		{3, -1, 7, 0},
		{7, 0, 5, 4},
		{6, -2, 0, 5}
	};
	copy_size = 4;
	float	**matrix_A = copy_matrix(matrix_A_values);
	float	**matrix_B = copy_matrix(matrix_B_values);
	float	**matrix_C = multiply_matrix(matrix_A, matrix_B);
	float	**inverse_B = inverse(matrix_B);
	float	**result = multiply_matrix(matrix_C, inverse_B);

	mu_assert(
		compare_matrices(result, matrix_A),
		"Multiplying by inverse did not return the original A matrix"
	);

	free_matrix(matrix_A);
	free_matrix(matrix_B);
	free_matrix(inverse_B);
	free_matrix(matrix_C);
	free_matrix(result);
}

MU_TEST_SUITE(test_matrix_invertion)
{
	MU_RUN_TEST(test_if_a_matrix_is_invertible);
	MU_RUN_TEST(test_if_a_matrix_is_uninvertible);
	MU_RUN_TEST(test_if_a_inverted_matrix_is_equal_to_a_received_matrix);
	MU_RUN_TEST(test_if_inverse_function_returns_correct_matrices_1);
	MU_RUN_TEST(test_if_inverse_function_returns_correct_matrices_2);
	MU_RUN_TEST(test_if_multiplying_by_inverse_gets_back_to_original_matrix);
}
