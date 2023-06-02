#include <minunit.h>
#include <minirt.h>

MU_TEST(test_should_calculate_minor_of_an_element_in_3x3_matrix)
{
	copy_size = 3;
	float	x[3][3] = {
		{3, 5, 0},
		{2, -1, -7},
		{6, -1, 5}
	};
	float	**A = copy_matrix(x);
	float	**B = submatrix(A, 1, 0);
	float	expected = 25;
	
	mu_assert_double_eq(determinant_2X2_matrix(B), 25);
	mu_assert_double_eq(minor(A, 1, 0), 25);

	free_matrix(A);
	free_matrix(B);
}

MU_TEST_SUITE(test_calculate_minor)
{
	MU_RUN_TEST(test_should_calculate_minor_of_an_element_in_3x3_matrix);
}
