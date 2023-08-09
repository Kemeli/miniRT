#include <minirt.h>
#include <minunit.h>

MU_TEST(test_validate_color_cases)
{
	mu_check(validate_color("255,150,212") == 1);
	mu_check(validate_color("0,0,0") == 1);
	mu_check(validate_color("0,1,2") == 1);
	mu_check(validate_color("0,150,98") == 1);
	mu_check(validate_color("3,200,0") == 1);
	mu_check(validate_color("14,0,110") == 1);
	mu_check(validate_color("255,255,256") == 0);
	mu_check(validate_color("0,0,0,0") == 0);
	mu_check(validate_color("0,1,2,3") == 0);
	mu_check(validate_color("0,150,98,0") == 0);
	mu_check(validate_color("3,200,-5") == 0);
	mu_check(validate_color("14,0,270") == 0);
	// mu_check(validate_color("14,0") == 0);
	// mu_check(validate_color("1e,0") == 0);
}

MU_TEST_SUITE(test_validate_color)
{
	MU_RUN_TEST(test_validate_color_cases);
}
