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

	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			mu_assert_double_eq(expected[i][j], m[i][j]);

	for(int i = 0; i < 2; i++)
		free(m[i]);
	free(m);
}

MU_TEST_SUITE(test_creating_matrix)
{
	MU_RUN_TEST(test_should_create_and_assign_right_values_to_a_2x2_matrix);
}
