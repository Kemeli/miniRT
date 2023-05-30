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

MU_TEST(test_should_calculate_minor_of_an_element_in_3x3_matrix)
{
	float	x[3][3] = {
		{3, 5, 0},
		{2, -1, -7},
		{6, -1, 5}
	};
	float	**A = copy_matrix_3x3(x);
	float	**B = submatrix(A, 1, 0);
	float	expected = 25;
	
	mu_assert_double_eq(determinant_2X2_matrix(B), 25);
	mu_assert_double_eq(minor(A, 1, 0), 25);

	free_matrix(A);
	free_matrix(B);
}

MU_TEST_SUITE(test_calculate_minor_test)
{
	MU_RUN_TEST(test_should_calculate_minor_of_an_element_in_3x3_matrix);
}
