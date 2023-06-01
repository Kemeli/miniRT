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

MU_TEST_SUITE(test_matrix_invertion)
{
	MU_RUN_TEST(test_if_a_matrix_is_invertible);
	MU_RUN_TEST(test_if_a_matrix_is_uninvertible);
	MU_RUN_TEST(test_if_a_inverted_matrix_is_equal_to_a_received_matrix);
}
