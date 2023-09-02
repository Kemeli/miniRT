#include <minirt.h>
#include <minunit.h>
#include <math.h>

MU_TEST(test_that_a_point_rotate_around_the_x_axis)
{
	t_tuple p = point(0, 1, 0);
	double **half_quarter = rotation_x(M_PI / 4);
	double **full_quarter = rotation_x(M_PI / 2);
	t_tuple expected_half_quarter = point(0, sqrt(2) / 2, sqrt(2) / 2);
	t_tuple expected_full_quarter = point(0, 0, 1);
	t_tuple result_half_quarter = multiply_matrix_with_tuple(half_quarter, p);
	t_tuple result_full_quarter = multiply_matrix_with_tuple(full_quarter, p);
	mu_check(compare_tuples(expected_half_quarter, result_half_quarter));
	mu_check(compare_tuples(expected_full_quarter, result_full_quarter));

	free(p);
	free(expected_half_quarter);
	free(expected_full_quarter);
	free(result_full_quarter);
	free(result_half_quarter);
	free_matrix(half_quarter);
	free_matrix(full_quarter);
}

MU_TEST(test_that_the_inverse_of_a_rotation_rotates_in_the_opposite_direction)
{
	t_tuple p = point(0, 1, 0);
	double **half_quarter = rotation_x(M_PI / 4);
	double **inv = inverse(half_quarter);
	t_tuple expected = point(0, sqrt(2) / 2, -sqrt(2) / 2);
	t_tuple result = multiply_matrix_with_tuple(inv, p);
	mu_check(compare_tuples(expected, result));

	free(p);
	free(expected);
	free(result);
	free_matrix(half_quarter);
	free_matrix(inv);
}

MU_TEST(test_that_a_point_rotate_around_the_y_axis)
{
	t_tuple p = point(0, 0, 1);
	double **half_quarter = rotation_y(M_PI / 4);
	double **full_quarter = rotation_y(M_PI / 2);
	t_tuple expected_half_quarter = point(sqrt(2) / 2, 0, sqrt(2) / 2);
	t_tuple expected_full_quarter = point(1, 0, 0);
	t_tuple result_half_quarter = multiply_matrix_with_tuple(half_quarter, p);
	t_tuple result_full_quarter = multiply_matrix_with_tuple(full_quarter, p);
	mu_check(compare_tuples(expected_half_quarter, result_half_quarter));
	mu_check(compare_tuples(expected_full_quarter, result_full_quarter));

	free(p);
	free(expected_half_quarter);
	free(expected_full_quarter);
	free(result_full_quarter);
	free(result_half_quarter);
	free_matrix(half_quarter);
	free_matrix(full_quarter);
}

MU_TEST(test_that_a_point_rotate_around_the_z_axis)
{
	t_tuple p = point(0, 1, 0);
	double **half_quarter = rotation_z(M_PI / 4);
	double **full_quarter = rotation_z(M_PI / 2);
	t_tuple expected_half_quarter = point(-sqrt(2) / 2, sqrt(2) / 2, 0);
	t_tuple expected_full_quarter = point(-1, 0, 0);
	t_tuple result_half_quarter = multiply_matrix_with_tuple(half_quarter, p);
	t_tuple result_full_quarter = multiply_matrix_with_tuple(full_quarter, p);
	mu_check(compare_tuples(expected_half_quarter, result_half_quarter));
	mu_check(compare_tuples(expected_full_quarter, result_full_quarter));

	free(p);
	free(expected_half_quarter);
	free(expected_full_quarter);
	free(result_full_quarter);
	free(result_half_quarter);
	free_matrix(half_quarter);
	free_matrix(full_quarter);
}

MU_TEST_SUITE(test_rotation)
{
	MU_RUN_TEST(test_that_a_point_rotate_around_the_x_axis);
	MU_RUN_TEST(test_that_the_inverse_of_a_rotation_rotates_in_the_opposite_direction);
	MU_RUN_TEST(test_that_a_point_rotate_around_the_y_axis);
	MU_RUN_TEST(test_that_a_point_rotate_around_the_z_axis);
}

