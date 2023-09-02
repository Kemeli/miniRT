#include <minirt.h>
#include <minunit.h>

MU_TEST(test_validate_angle_cases)
{
	double	n0 = validate_angle("75");
	double	n1 = validate_angle("180.1");
	double	n2 = validate_angle("-80.1");
	double	n3 = validate_angle("0,785");
	double	n4 = validate_angle("0.785");
	double	n5 = validate_angle("0.a85");
	double	n6 = validate_angle("n");
	double	n7 = validate_angle("10.9");
	double	n8 = validate_angle(".0.785");
	double	n9 = validate_angle("0..785");


	// printf("\nn0 = %f\n", n0);
	mu_check(n0 == 75.0f);
	mu_check(n1 == -1.0f);
	mu_check(n2 == -1.0f);
	mu_check(n3 == -1.0f);
	mu_check(n4 == 0.785f);
	mu_check(n5 == -1.0f);
	mu_check(n6 == -1.0f);
	mu_check(n7 == 10.9f);
	mu_check(n8 == -1.0f);
	mu_check(n9 == -1.0f);

}

MU_TEST_SUITE(test_validate_angle)
{
	MU_RUN_TEST(test_validate_angle_cases);
}
