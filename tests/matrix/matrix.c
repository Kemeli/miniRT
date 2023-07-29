#include <minunit.h>
#include <minirt.h>

MU_TEST(test_should_create_and_assign_right_values_to_a_2x2_matrix)
{
	float	expected[2][2] = {
		{-3, 5},
		{1, -2}
	};
	float	**m = matrix(2);
	m[0][0] = -3;
	m[0][1] = 5;
	m[1][0] = 1;
	m[1][1] = -2;

	mu_assert_double_eq(expected[0][0], m[0][0]);
	mu_assert_double_eq(expected[0][1], m[0][1]);
	mu_assert_double_eq(expected[0][1], m[0][1]);
	mu_assert_double_eq(expected[1][1], m[1][1]);

	free_matrix(m);
}

MU_TEST(test_should_create_and_assign_right_values_to_a_3x3_matrix)
{
	float	expected[3][3] = {
		{-3, 5, 0},
		{1, -2, -7},
		{0, 1, 1}
	};
	float	**m = matrix(3);
	m[0][0] = -3;
	m[0][1] = 5;
	m[0][2] = 0;
	m[1][0] = 1;
	m[1][1] = -2;
	m[1][2] = -7;
	m[2][0] = 0;
	m[2][1] = 1;
	m[2][2] = 1;

	mu_assert_double_eq(expected[0][0], m[0][0]);
	mu_assert_double_eq(expected[0][1], m[0][1]);
	mu_assert_double_eq(expected[0][2], m[0][2]);
	mu_assert_double_eq(expected[1][0], m[1][0]);
	mu_assert_double_eq(expected[1][1], m[1][1]);
	mu_assert_double_eq(expected[1][2], m[1][2]);
	mu_assert_double_eq(expected[2][0], m[2][0]);
	mu_assert_double_eq(expected[2][1], m[2][1]);
	mu_assert_double_eq(expected[2][2], m[2][2]);

	free_matrix(m);
}

MU_TEST(test_should_create_and_assign_right_values_to_a_4x4_matrix)
{
	float	expected[4][4] = {
		{1, 2, 3, 4},
		{5.5, 6.5, 7.5, 8.5},
		{9, 10, 11, 12},
		{13.5, 14.5, 15.5, 16.5}
	};
	float	**m = matrix(4);
	m[0][0] = 1;
	m[0][1] = 2;
	m[0][2] = 3;
	m[0][3] = 4;
	m[1][0] = 5.5;
	m[1][1] = 6.5;
	m[1][2] = 7.5;
	m[1][3] = 8.5;
	m[2][0] = 9;
	m[2][1] = 10;
	m[2][2] = 11;
	m[2][3] = 12;
	m[3][0] = 13.5;
	m[3][1] = 14.5;
	m[3][2] = 15.5;
	m[3][3] = 16.5;

	mu_assert_double_eq(expected[0][0], m[0][0]);
	mu_assert_double_eq(expected[0][1], m[0][1]);
	mu_assert_double_eq(expected[0][2], m[0][2]);
	mu_assert_double_eq(expected[1][0], m[1][0]);
	mu_assert_double_eq(expected[1][1], m[1][1]);
	mu_assert_double_eq(expected[1][2], m[1][2]);
	mu_assert_double_eq(expected[2][0], m[2][0]);
	mu_assert_double_eq(expected[2][1], m[2][1]);
	mu_assert_double_eq(expected[2][2], m[2][2]);

	free_matrix(m);
}

MU_TEST(test_matrix_should_have_a_null_at_the_end)
{
	int	size = 4;
	t_matrix m = matrix(size);

	mu_check(m[size] == NULL);

	free_matrix(m);
}

MU_TEST_SUITE(test_creating_matrix)
{
	MU_RUN_TEST(test_should_create_and_assign_right_values_to_a_2x2_matrix);
	MU_RUN_TEST(test_should_create_and_assign_right_values_to_a_3x3_matrix);
	MU_RUN_TEST(test_should_create_and_assign_right_values_to_a_4x4_matrix);
	MU_RUN_TEST(test_matrix_should_have_a_null_at_the_end);
}
