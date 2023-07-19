#include <minirt.h>
#include <minunit.h>

MU_TEST(test_the_transformation_matrix_for_the_default_orientation)
{
	t_tuple		from = point(0, 0, 0);
	t_tuple		to = point(0, 0, -1);
	t_tuple		up = vector(0, 1, 0);
	t_matrix	t;
	t_matrix	expected = identity_matrix(4);

	t = view_transform(from, to, up);

	mu_check(compare_matrices(expected, t));

	free_matrix(expected);
	free_matrix(t);
	free(from);
	free(to);
	free(up);
}

MU_TEST(test_a_view_transformation_matrix_looking_in_positive_z_direction)
{
	t_tuple		from = point(0, 0, 0);
	t_tuple		to = point(0, 0, 1);
	t_tuple		up = vector(0, 1, 0);
	t_matrix	t;
	t_matrix	expected = scaling(-1, 1, -1);

	t = view_transform(from, to, up);

	mu_check(compare_matrices(expected, t));

	free_matrix(expected);
	free_matrix(t);
	free(from);
	free(to);
	free(up);
}

MU_TEST(test_the_view_transformation_moves_the_world)
{
	t_tuple		from = point(0, 0, 8);
	t_tuple		to = point(0, 0, 0);
	t_tuple		up = vector(0, 1, 0);
	t_matrix	t;
	t_matrix	expected = translation(0, 0, -8);

	t = view_transform(from, to, up);

	mu_check(compare_matrices(expected, t));

	free_matrix(expected);
	free_matrix(t);
	free(from);
	free(to);
	free(up);
}

MU_TEST(test_an_arbitrary_view_transformation)
{
	t_tuple		from = point(1, 3, 2);
	t_tuple		to = point(4, -2, 8);
	t_tuple		up = vector(1, 1, 0);
	t_matrix	t;
	t_matrix	expected;

	expected = matrix(4);
	t = view_transform(from, to, up);

	float		aux[4][4] = {
		{-0.50709, 0.50709, 0.67612, -2.36643},
		{0.76772, 0.60609, 0.12122, -2.82843},
		{-0.35857, 0.59761, -0.71714, 0.00000},
		{0.00000, 0.00000, 0.00000, 1.00000}
	};

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			expected[i][j] = aux[i][j];

	mu_check(compare_matrices(expected, t));

	free_matrix(t);
	free_matrix(expected);
	free(from);
	free(to);
	free(up);
}

MU_TEST_SUITE(test_view_transform)
{
	MU_RUN_TEST(test_the_transformation_matrix_for_the_default_orientation);
	MU_RUN_TEST(test_a_view_transformation_matrix_looking_in_positive_z_direction);
	MU_RUN_TEST(test_the_view_transformation_moves_the_world);
	MU_RUN_TEST(test_an_arbitrary_view_transformation);
}
