#include <minirt.h>
#include <minunit.h>

MU_TEST(test_validate_color_cases)
{
	mu_check(validate_color("255,150,212"));
	mu_check(validate_color("0,0,0"));
	mu_check(validate_color("0,1,2"));
	mu_check(validate_color("0,150,98"));
	mu_check(validate_color("3,200,0"));
	mu_check(validate_color("14,0,110"));

	mu_check(!validate_color("255,255,256"));
	mu_check(!validate_color("0,0,0,0"));
	mu_check(!validate_color("0,1,2,3"));
	mu_check(!validate_color("0,150,98,0"));
	mu_check(!validate_color("3,200,-5"));
	mu_check(!validate_color("14,0,270"));
	mu_check(!validate_color("14,0"));
	mu_check(!validate_color("1e,0"));
	mu_check(!validate_color("14,0"));
	mu_check(!validate_color("1e,,0"));
	mu_check(!validate_color("14,0,110,"));
	mu_check(!validate_color("14,0,110,5"));
	mu_check(!validate_color("14,0,110,5,0"));
}

MU_TEST_SUITE(test_validate_color)
{
	MU_RUN_TEST(test_validate_color_cases);
}
