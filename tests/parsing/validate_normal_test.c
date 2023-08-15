#include <minirt.h>
#include <minunit.h>

MU_TEST(test_validate_normal_cases)
{
	//Point at the center of the field of view:
	t_tuple	expected1 = vector(-1.0, 0.0, 0.0);
	//Point slightly to the right:
	t_tuple	expected2 = vector(1.0, 1.0, 1.0);
	//Point slightly above the center:
	t_tuple	expected3 = vector(0.0, 0.0, 0.0);
	//Point at the edge of the field of view to the left:
	t_tuple	expected4 = vector(0.8, 0.0, 0.3);
	//Point at the edge of the field of view to the right:
	t_tuple	expected5 = vector(-0.8, 1.0, -0.3);
	t_tuple	expected6 = vector(0, 0, 1);

	t_tuple p1 = validate_normal("-1.0,0.0,0.0");
	t_tuple p2 = validate_normal("1.0,1.0,1.0");
	t_tuple p3 = validate_normal("0.0,0.0,0.0");
	t_tuple p4 = validate_normal("0.8,0.0,0.3");
	t_tuple p5 = validate_normal("-0.8,1.0,-0.3");
	t_tuple p6 = validate_normal("0,0,1");
	t_tuple p7 = validate_normal("-33,0.02");
	t_tuple p8 = validate_normal("-33,0.2,1.0");
	t_tuple p9 = validate_normal("-33,0.2,1.0,0.0");

	mu_check(compare_tuples(expected1, p1));
	mu_check(compare_tuples(expected2, p2));
	mu_check(compare_tuples(expected3, p3));
	mu_check(compare_tuples(expected4, p4));
	mu_check(compare_tuples(expected5, p5));
	mu_check(compare_tuples(expected6, p6));
	mu_check(p7 == NULL);
	mu_check(p8 == NULL);
	mu_check(p9 == NULL);

	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(expected1);
	free(expected2);
	free(expected3);
	free(expected4);
	free(expected5);
	free(expected6);
}

MU_TEST_SUITE(test_validate_normal_parsing)
{
	MU_RUN_TEST(test_validate_normal_cases);
}
