#include <minunit.h>
#include <minirt.h>

MU_TEST(test_color_multiplication_of_1_02_04_and_09_1_01_shoulbe_be_09_004)
{
	t_tuple	c1 = color(1, 0.2, 0.4);
	t_tuple	c2 = color(0.9, 1, 0.1);
	t_tuple	expected = color(0.9, 0.2, 0.04);
	t_tuple	result = multiply_colors(c1, c2);
	mu_assert(
		compare_tuples(result, expected),
		"product of colors (1, 0.2, 0.4, 0) and (0.9, 1, 0.1, 0) should be (0.9, 0.2, 0.04, 0)"
	);
	free(c1);
	free(c2);
	free(expected);
	free(result);
}

MU_TEST_SUITE(test_color_mutltiplication)
{
	MU_RUN_TEST(test_color_multiplication_of_1_02_04_and_09_1_01_shoulbe_be_09_004);
}
