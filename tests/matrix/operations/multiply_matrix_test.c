#include <minunit.h>
#include <minirt.h>
#include <stdio.h>

MU_TEST(test_multiple_two_4x4_matrices)
{
	double x[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}
	};
	double y[4][4] = {
		{-2, 1, 2, 3},
		{3, 2, 1, -1},
		{4, 3, 6, 5},
		{1, 2, 7, 8}
	};
	double z[4][4] = {
		{20, 22, 50, 48},
		{44, 54, 114, 108},
		{40, 58, 110, 102},
		{16, 26, 46, 42}
	};

	copy_size = 4;
	double	**a = copy_matrix(x);
	double	**b = copy_matrix(y);
	double	**expected = copy_matrix(z);
	double	**result = multiply_matrix(a, b);

	mu_check(compare_matrices(result, expected));

	free_matrix(a);
	free_matrix(b);
	free_matrix(expected);
	free_matrix(result);
}

MU_TEST(test_multiply_matrix_with_a_tuple)
{
	t_tuple	result;
	double	**matrix_A = matrix(4);
	t_tuple	tuple_A = tuple(1, 2, 3, 1);
	t_tuple	expected = tuple(18, 24, 33, 1);

	double	matrix_values[4][4] = {
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
	double	m[4][4] = {
		{0, 1, 2, 4},
		{1, 2, 4, 8},
		{2, 4, 8, 16},
		{4, 8, 16, 32}
	};
	double	**original = copy_matrix(m);
	double	**identity = identity_matrix(4);
	double	**result = multiply_matrix(original, identity);

	mu_assert(
		compare_matrices(result, original),
		"multiply a matrix by an indentity should return the matrix itself"
	);

	free_matrix(original);
	free_matrix(identity);
	free_matrix(result);
}

MU_TEST(test_multiplying_tuple_by_an_indentity_should_return_the_matrix_itself)
{
	t_tuple	a = tuple(1, 2, 3, 4);
	double	**identity = identity_matrix(4);
	t_tuple	result = multiply_matrix_with_tuple(identity, a);

	mu_assert(
		compare_tuples(a, result),
		"multiply a tuple by an indentity should return the matrix itself"
	);

	free(a);
	free(result);
	free_matrix(identity);
}

MU_TEST_SUITE(test_multiply_matrix)
{
	MU_RUN_TEST(test_multiple_two_4x4_matrices);
	MU_RUN_TEST(test_multiply_matrix_with_a_tuple);
	MU_RUN_TEST(test_multiplying_matrix_by_an_indentity_should_return_the_matrix_itself);
	MU_RUN_TEST(test_multiplying_tuple_by_an_indentity_should_return_the_matrix_itself);
}
