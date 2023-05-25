#include <minunit.h>
#include <minirt.h>

static float	**copy_matrix(float a[4][4])
{
	float	**m = matrix(4);
	for(int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			m[i][j] = a[i][j];
	return (m);
}

MU_TEST(test_multiple_two_4x4_matrices)
{
	float x[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}
	};
	float y[4][4] = {
		{-2, 1, 2, 3},
		{3, 2, 1, -1},
		{4, 3, 6, 5},
		{1, 2, 7, 8}
	};
	float z[4][4] = {
		{20, 22, 50, 48},
		{44, 54, 114, 108},
		{40, 58, 110, 102},
		{16, 26, 46, 42}
	};

	float	**a = copy_matrix(x);
	float	**b = copy_matrix(y);
	float	**expected = copy_matrix(z);
	float	**result = multiply_matrix(a, b);

	mu_check(compare_matrices(result, expected));

	free_matrix(a);
	free_matrix(b);
	free_matrix(expected);
	free_matrix(result);
}

MU_TEST_SUITE(test_multiply_matrix)
{
	MU_RUN_TEST(test_multiple_two_4x4_matrices);
}
