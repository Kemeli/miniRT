#include <minirt.h>
#include <minunit.h>

MU_TEST(test_is_float_cases)
{

	mu_check(is_float("75") == 1);
	mu_check(is_float("n") == 0);
	mu_check(is_float("0.a") == 0);
	mu_check(is_float("0,1") == 0);
	mu_check(is_float("7.5") == 1);
	mu_check(is_float("7..5") == 0);
	mu_check(is_float(".7.5") == 0);
	mu_check(is_float("0") == 1);
}

MU_TEST_SUITE(test_is_float)
{
	MU_RUN_TEST(test_is_float_cases);
}