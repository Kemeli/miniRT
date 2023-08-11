#include <minirt.h>
#include <minunit.h>

MU_TEST(test_validate_angle_cases)
{
	float	n0 = validate_angle("75");
	float	n1 = validate_angle("180.1");
	float	n2 = validate_angle("-80.1");
	float	n3 = validate_angle("0,785");
	float	n4 = validate_angle("0.785");

	// printf("\nn3 = %f\n", n3);
	mu_check(n0 == 75.0f);
	mu_check(n1 == -1.0f);
	mu_check(n2 == -1.0f);
	mu_check(n3 == -1.0f);
	mu_check(n4 == 0.785f);
}

MU_TEST_SUITE(test_validate_angle)
{
	MU_RUN_TEST(test_validate_angle_cases);
}
