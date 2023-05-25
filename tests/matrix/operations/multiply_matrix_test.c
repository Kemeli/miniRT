#include <minunit.h>
#include <minirt.h>
#include <stdio.h>

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

MU_TEST(test_multiply_matrix_with_a_tuple)
{
	t_tuple	result;
	float	**matrix_A = matrix(4);
	t_tuple	tuple_A = tuple(1, 2, 3, 1);
	t_tuple	expected = tuple(18, 24, 33, 1);

	float	matrix_values[4][4] = {
		{1, 2, 3, 4},
		{2, 4, 4, 2},
		{8, 6, 4, 1},
		{0, 0, 0, 1}
	};

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++)
			matrix_A[i][j] = matrix_values[i][j];
	}

	result = multiply_matrix_with_tuple(matrix_A, tuple_A);
	mu_check(compare_tuples(result, expected));
	free_matrix(matrix_A);
	free(tuple_A);
	free(result);
	free(expected);
}

MU_TEST(test_multiplying_matrix_by_an_indentity_should_return_the_matrix_itself)
{
	float	m[4][4] = {
		{0, 1, 2, 4},
		{1, 2, 4, 8},
		{2, 4, 8, 16},
		{4, 8, 16, 32}
	};
	float	**original = copy_matrix(m);
	float	**identity = identity_matrix(4);
	float	**result = multiply_matrix(original, identity);

	mu_assert(
		compare_matrices(result, original),
		"multiply a matrix by an indentity should return the matrix itself"
	);

	free_matrix(original);
	free_matrix(identity);
	free_matrix(result);
}

MU_TEST_SUITE(test_multiply_matrix)
{
	MU_RUN_TEST(test_multiple_two_4x4_matrices);
	MU_RUN_TEST(test_multiply_matrix_with_a_tuple);
	MU_RUN_TEST(test_multiplying_matrix_by_an_indentity_should_return_the_matrix_itself);
}
