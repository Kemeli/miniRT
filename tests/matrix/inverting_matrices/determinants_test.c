#include <minunit.h>
#include <minirt.h>

MU_TEST(test_determinant_of_matrix_2x2_values_1_5_minus_3_2_is_17)
{
	t_matrix	matrix_A = matrix(2);
	float	matrix_values[2][2] = {
		{1, 5},
		{-3, 2}
	};
	float	expected = 17;

	for(int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			matrix_A[i][j] = matrix_values[i][j];

	mu_check(determinant_2X2_matrix(matrix_A) == expected);
	free_matrix(matrix_A);
}

MU_TEST(test_determinant_of_3x3_matrix)
{
	float matrix_A_values[3][3] = {
		{1, 2, 6},
		{-5, 8, -4},
		{2, 6, 4}
	};
	copy_size = 3;
	t_matrix matrix_A = copy_matrix(matrix_A_values);
	mu_assert_double_eq(cofactor(matrix_A, 0, 0), 56);
	mu_assert_double_eq(cofactor(matrix_A, 0, 1), 12);
	mu_assert_double_eq(cofactor(matrix_A, 0, 2), -46);
	mu_assert_double_eq(determinant(matrix_A), -196);
	free_matrix(matrix_A);
}

MU_TEST(test_determinant_of_4x4_matrix)
{
	float matrix_A_values[4][4] = {
		{-2, -8, 3, 5},
		{-3, 1, 7, 3},
		{1, 2, -9, 6},
		{-6, 7, 7, -9}
	};
	copy_size = 4;
	t_matrix matrix_A = copy_matrix(matrix_A_values);
	mu_assert_double_eq(cofactor(matrix_A, 0, 0), 690);
	mu_assert_double_eq(cofactor(matrix_A, 0, 1), 447);
	mu_assert_double_eq(cofactor(matrix_A, 0, 2), 210);
	mu_assert_double_eq(cofactor(matrix_A, 0, 3), 51);
	mu_assert_double_eq(determinant(matrix_A), -4071);
	free_matrix(matrix_A);
}

MU_TEST_SUITE(test_matrix_determinant)
{
	MU_RUN_TEST(test_determinant_of_matrix_2x2_values_1_5_minus_3_2_is_17);
	MU_RUN_TEST(test_determinant_of_3x3_matrix);
	MU_RUN_TEST(test_determinant_of_4x4_matrix);
}
