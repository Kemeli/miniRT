#include <minunit.h>
#include <minirt.h>

MU_TEST(test_calculate_of_a_element_in_a_3x3_matrix)
{
	copy_size = 3;
	double	x[3][3] = {
		{3, 5, 0},
		{2, -1, -7},
		{6, -1, 5}
	};
	double	**A = copy_matrix(x);
	double	minor_result = minor(A, 0, 0);
	double	cofactor_result = cofactor(A, 0, 0);
	double	expected = -12;

	mu_assert_double_eq(minor_result, expected);
	mu_assert_double_eq(cofactor_result, expected);

	minor_result = minor(A, 1, 0);
	cofactor_result = cofactor(A, 1, 0);

	mu_assert_double_eq(minor_result, 25);
	mu_assert_double_eq(cofactor_result, -25);

	free_matrix(A);
}

MU_TEST_SUITE(test_calculate_cofactor)
{
	MU_RUN_TEST(test_calculate_of_a_element_in_a_3x3_matrix);
}
