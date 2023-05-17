#include <minunit.h>
#include <minirt.h>

MU_TEST(test_dot_product_of_two_tuples)
{
	t_tuple	v = vector(1, 2, 3);
	t_tuple	w = vector(2, 3, 4);
	float	expected = 20;
	float	result = dot(v, w);

	mu_assert_double_eq(result, expected);

	free(v);
	free(w);
}

MU_TEST_SUITE(test_dot_product)
{
	MU_RUN_TEST(test_dot_product_of_two_tuples);
}
