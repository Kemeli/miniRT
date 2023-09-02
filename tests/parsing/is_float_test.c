#include <minirt.h>
#include <minunit.h>

MU_TEST(test_is_double_cases)
{

	mu_check(is_double("75") == 1);
	mu_check(is_double("n") == 0);
	mu_check(is_double("0.a") == 0);
	mu_check(is_double("0,1") == 0);
	mu_check(is_double("7.5") == 1);
	mu_check(is_double("7..5") == 0);
	mu_check(is_double(".7.5") == 0);
	mu_check(is_double("0") == 1);
}

MU_TEST_SUITE(test_is_double)
{
	MU_RUN_TEST(test_is_double_cases);
}
