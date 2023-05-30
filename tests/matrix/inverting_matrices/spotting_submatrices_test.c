#include <minirt.h>
#include <minunit.h>

MU_TEST(test_matrix_1_5_0_minus_3_2_7_0_6_minus_3_spotting_submatrix_is_minus_3_2_0_6)
{
	int		row = 0;
	int		col = 2;
	float	matrix_values[3][3] = {
		{1, 5, 0},
		{-3, 2, 7},
		{0, 6, -3}
	};
	float	expected_values[2][2] = {
		{-3, 2},
		{0, 6}
	};

	float **original_matrix = matrix(3);
	float **expected = matrix(2);
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			original_matrix[i][j] = matrix_values[i][j];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			expected[i][j] = expected_values[i][j];

	float **result =  submatrix(original_matrix, row, col);
	mu_check(compare_matrices(result, expected));
	free_matrix(original_matrix);
	free_matrix(expected);
	free_matrix(result);
}

MU_TEST_SUITE(test_spotting_submatrices)
{
	MU_RUN_TEST(test_matrix_1_5_0_minus_3_2_7_0_6_minus_3_spotting_submatrix_is_minus_3_2_0_6);
}
