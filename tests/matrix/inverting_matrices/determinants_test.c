#include <minunit.h>
#include <minirt.h>

MU_TEST(test_determinant_of_matrix_2x2_values_1_5_minus_3_2_is_17)
{
	float	**matrix_A = matrix(2);
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

MU_TEST_SUITE(test_matrix_determinant)
{
	MU_RUN_TEST(test_determinant_of_matrix_2x2_values_1_5_minus_3_2_is_17);
}
