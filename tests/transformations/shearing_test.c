#include <minirt.h>
#include <minunit.h>

// nos parametros estou passando a posição e o valor

MU_TEST(test_that_a_shearing_transformation_moves_x_in_proportion_to_y)
{
	float **transform = shearing(0, 1);
	t_tuple p = point(2, 3, 4);
	t_tuple expected = point (5, 3, 4);
	t_tuple result = multiply_matrix_with_tuple(transform, p);
	mu_check(compare_tuples(expected, result));

	free(p);
	free(expected);
	free(result);
	free_matrix(transform);
}

MU_TEST(test_that_a_shearing_transformation_moves_x_in_proportion_to_z)
{
	float **transform = shearing(1, 1);
	t_tuple p = point (2, 3, 4);
	t_tuple expected = point(6, 3, 4);
	t_tuple result = multiply_matrix_with_tuple(transform, p);
	mu_check(compare_tuples(expected, result));

	free(p);
	free(expected);
	free(result);
	free_matrix(transform);
}

MU_TEST(test_that_a_shearing_transformation_moves_y_in_proportion_to_x)
{
	float **transform = shearing(2, 1);
	t_tuple p = point (2, 3, 4);
	t_tuple expected = point(2, 5, 4);
	t_tuple result = multiply_matrix_with_tuple(transform, p);
	mu_check(compare_tuples(expected, result));

	free(p);
	free(expected);
	free(result);
	free_matrix(transform);
}

MU_TEST(test_that_a_shearing_transformation_moves_y_in_proportion_to_z)
{
	float **transform = shearing(3, 1);
	t_tuple p = point(2, 3, 4);
	t_tuple expected = point(2, 7, 4);
	t_tuple result = multiply_matrix_with_tuple(transform, p);
	mu_check(compare_tuples(expected, result));

	free(p);
	free(expected);
	free(result);
	free_matrix(transform);
}

MU_TEST(test_that_a_shearing_transformation_moves_z_in_proportion_to_x)
{
	float **transform = shearing(4, 1);
	t_tuple p = point(2, 3, 4);
	t_tuple expected =  point(2, 3, 6);
	t_tuple result = multiply_matrix_with_tuple(transform, p);
	mu_check(compare_tuples(expected, result));

	free(p);
	free(expected);
	free(result);
	free_matrix(transform);
}

MU_TEST(test_that_a_shearing_transformation_moves_z_in_proportion_to_y)
{
	float **transform = shearing(5, 1);
	t_tuple p = point(2, 3, 4);
	t_tuple expected = point(2, 3, 7);
	t_tuple result = multiply_matrix_with_tuple(transform, p);
	mu_check(compare_tuples(expected, result));

	free(p);
	free(expected);
	free(result);
	free_matrix(transform);
}
MU_TEST_SUITE(shearing_test)
{
	MU_RUN_TEST(test_that_a_shearing_transformation_moves_x_in_proportion_to_y);
	MU_RUN_TEST(test_that_a_shearing_transformation_moves_x_in_proportion_to_z);
	MU_RUN_TEST(test_that_a_shearing_transformation_moves_y_in_proportion_to_x);
	MU_RUN_TEST(test_that_a_shearing_transformation_moves_y_in_proportion_to_z);
	MU_RUN_TEST(test_that_a_shearing_transformation_moves_z_in_proportion_to_x);
	MU_RUN_TEST(test_that_a_shearing_transformation_moves_z_in_proportion_to_y);
}
