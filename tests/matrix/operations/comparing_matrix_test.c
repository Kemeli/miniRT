#include <minunit.h>
#include <minirt.h>

MU_TEST(test_matrix_4x4_are_equal)
{
	float	values[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}
	};
	float	**matrix_A = matrix(4);
	float	**matrix_B = matrix(4);
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			matrix_A[i][j] = values[i][j];
			matrix_B[i][j] = values[i][j];
		}
	}
	mu_assert(compare_matrices(matrix_A, matrix_B), "matrices should be equal");
	free_matrix(matrix_A);
	free_matrix(matrix_B);

}

MU_TEST(test_matrix_4x4_are_different)
{
	float	values_A[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}
	};
	float	values_B[4][4] = {
		{1, 3, 4, 5},
		{6, 6, 8, 9},
		{8, 7, 7, 5},
		{4, 3, 2, 2}
	};
	float	**matrix_A = matrix(4);
	float	**matrix_B = matrix(4);
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			matrix_A[i][j] = values_A[i][j];
			matrix_B[i][j] = values_B[i][j];
		}
	}
	mu_assert(!compare_matrices(matrix_A, matrix_B), "matrices should be different");
	free_matrix(matrix_A);
	free_matrix(matrix_B);
}

MU_TEST_SUITE(test_comparing_matrices)
{
	MU_RUN_TEST(test_matrix_4x4_are_equal);
	MU_RUN_TEST(test_matrix_4x4_are_different);
}
