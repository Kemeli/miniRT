#include <minunit.h>
#include <minirt.h>

MU_TEST(test_transposed_row_0930_should_become_col_0930)
{
	float	**matrix_A = matrix(4);
	float	**result;
	float	**expected = matrix(4);
	float	values_matrix_A[4][4] = {
		{0, 9, 3, 0},
		{9, 8, 0, 8},
		{1, 8, 5, 3},
		{0, 0, 5, 8}
	};

	float values_expected[4][4] = {
		{0, 9, 1, 0},
		{9, 8, 8, 0},
		{3, 0, 5, 5},
		{0, 8, 3, 8}
	};

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++){
			matrix_A[i][j] = values_matrix_A[i][j];
			expected[i][j] = values_expected[i][j];
		};
	};

	result = transpose_matrix(matrix_A);
	mu_check(compare_matrices(result, expected));

	free_matrix(matrix_A);
	free_matrix(result);
	free_matrix(expected);
}

MU_TEST(test_transpose_identity_matrix_should_return_itself)
{
	float	**identity = identity_matrix(4);
	float	**result = transpose_matrix(identity);
	float	**expected = identity;

	mu_assert(
		compare_matrices(result, expected),
		"Transposing a identity matrix should return itself"
	);

	free_matrix(identity);
	free_matrix(result);
}

MU_TEST_SUITE(test_transposing_matrix)
{
	MU_RUN_TEST(test_transposed_row_0930_should_become_col_0930);
	MU_RUN_TEST(test_transpose_identity_matrix_should_return_itself);
}
