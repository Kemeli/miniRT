#include <minirt.h>
#include <minunit.h>

MU_TEST(test_cross_product_of_vectors_1_2_3_and_2_3_4)
{
	t_tuple	a = vector(1, 2, 3);
	t_tuple b = vector(2, 3, 4);
	t_tuple	result_a_b = cross(a, b);
	t_tuple	expected_a_b = vector(-1, 2, -1);
	t_tuple	result_b_a = cross(b, a);
	t_tuple	expected_b_a = vector(1, -2, 1);

	mu_assert(
		compare_tuples(result_a_b, expected_a_b), 
		"product of vectors (1 2 3) and (2 3 4) should be equal to (-1 2 -1)"
	);
	mu_assert(
		compare_tuples(result_b_a, expected_b_a), 
		"product of vectors (2 3 4) and (1 2 3) should be equal to (1 -2 1)"
	);
	free (a);
	free (b);
	free (expected_a_b);
	free (expected_b_a);
	free (result_a_b);
	free (result_b_a);
}

MU_TEST_SUITE(test_cross_product)
{
	MU_RUN_TEST(test_cross_product_of_vectors_1_2_3_and_2_3_4);
}
