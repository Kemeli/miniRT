#include <minunit.h>
#include <minirt.h>

MU_TEST(test_point_identifier)
{
	t_tuple	a = tuple(4.3, -4.2, 3.1, 1.0);

	mu_assert_double_eq(a[0], 4.3);
	mu_assert_double_eq(a[1], -4.2);
	mu_assert_double_eq(a[2], 3.1);
	mu_assert(a[3] == 1.0, "tuple 'a' should be a point");
}

MU_TEST_SUITE(test_tuple_identifier)
{
	MU_RUN_TEST(test_point_identifier);
}
