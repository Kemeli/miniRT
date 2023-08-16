#include <minirt.h>
#include <minunit.h>

MU_TEST(test_count_comma)
{

	int	i0 = 0;
	int	comma0 = 0;

	count_comma(&i0, &comma0);
	mu_check(comma0 == 1);
	mu_check(i0 == 1);
}

MU_TEST_SUITE(test_utils_parsing)
{
	MU_RUN_TEST(test_count_comma);
}