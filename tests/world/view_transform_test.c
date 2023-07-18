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

MU_TEST_SUITE(test_view_transform)
{
	MU_RUN_TEST(test_the_transformation_matrix_for_the_default_orientation);
}
