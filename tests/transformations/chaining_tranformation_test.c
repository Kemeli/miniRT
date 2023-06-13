#include <minirt.h>
#include <minunit.h>

MU_TEST(test_that_individual_transformations_are_applied_in_sequence)
{
	t_tuple p = point(1, 0, 1);
	float **a = rotation_x(M_PI / 2);
	float **b = scaling(5, 5, 5);
	float **c = translation(10, 5, 7);
	// apply rotation first
	t_tuple p2 = multiply_matrix_with_tuple(a, p);
	t_tuple p2_expected = point(1, -1, 0);
	mu_check(compare_tuples(p2, p2_expected));
	// then apply scaling
	t_tuple p3 = multiply_matrix_with_tuple(b, p2);
	t_tuple p3_expected = point(5, -5, 0);
	mu_check(compare_tuples(p3, p3_expected));
	//  then apply translation
	t_tuple p4 = multiply_matrix_with_tuple(c, p3);
	t_tuple p4_expected = point(15, 0, 7);
	mu_check(compare_tuples(p4, p4_expected));

	free_matrix(a);
	free_matrix(b);
	free_matrix(c);
	free(p);
	free(p2);
	free(p3);
	free(p4);
	free(p2_expected);
	free(p3_expected);
	free(p4_expected);
}

MU_TEST(test_that_chained_transformation_must_be_applied_in_reverse_order)
{
	t_tuple p = point(1, 0, 1);
	float **a = rotation_x(M_PI / 2);
	float **b = scaling(5, 5, 5);
	float **c = translation(10, 5, 7);
	float **t = multiply_matrix(c, b);
	float **t2 = multiply_matrix(t, a);
	t_tuple p2 = multiply_matrix_with_tuple(t2, p);
	t_tuple p2_expected = point(15, 0, 7);
	mu_check(compare_tuples(p2, p2_expected));

	free_matrix(a);
	free_matrix(b);
	free_matrix(c);
	free_matrix(t);
	free_matrix(t2);
	free(p);
	free(p2);
	free(p2_expected);
}

MU_TEST_SUITE(test_chaining_transformations)
{
	MU_RUN_TEST(test_that_individual_transformations_are_applied_in_sequence);
	MU_RUN_TEST(test_that_chained_transformation_must_be_applied_in_reverse_order);
}
