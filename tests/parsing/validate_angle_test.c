#include <minirt.h>
#include <minunit.h>

MU_TEST(test_validate_angle_cases)
{
	float	n0 = validate_angle("75");
	float	n1 = validate_angle("180.1");

	// printf("\nn1 = %f\n", n1);
	mu_check(n0 == 75.0f);
	mu_check(n1 == 0.0f);
}

MU_TEST_SUITE(test_validate_angle)
{
	MU_RUN_TEST(test_validate_angle_cases);
}
