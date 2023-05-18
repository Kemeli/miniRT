#include <minunit.h>
#include <minirt.h>

MU_TEST(test_should_create_color_with_correct_parameters)
{
	t_tuple	c = color(-0.5, 0.4, 1.7);
	mu_assert_double_eq(c[0], -0.5); // red
	mu_assert_double_eq(c[1], 0.4); // green
	mu_assert_double_eq(c[2], 1.7); // blue
	free(c);
}

MU_TEST_SUITE(test_color_creation)
{
	MU_RUN_TEST(test_should_create_color_with_correct_parameters);
}
