#include <minirt.h>
#include <minunit.h>

MU_TEST(test_validate_coordinates)
{
	//Point at the center of the field of view:
	t_tuple	expected1 = point(-50.0, 0.0, 20.0);
	//Point slightly to the right:
	t_tuple	expected2 = point(-45.0, 0.0, 20.0);
	//Point slightly above the center:
	t_tuple	expected3 = point(-50.0, 5.0, 20.0);
	//Point at the edge of the field of view to the left:
	t_tuple	expected4 = point(-66.83, 0.0, 32.83);
	//Point at the edge of the field of view to the right:
	t_tuple	expected5 = point(-33.17, 0.0, 32.83);
	t_tuple	expected6 = point(-33, 0.0, 32);

	t_tuple p1 = validate_coordinates("-50.0,0.0,20.0");
	t_tuple p2 = validate_coordinates("-45.0,0.0,20.0");
	t_tuple p3 = validate_coordinates("-50.0,5.0,20.0");
	t_tuple p4 = validate_coordinates("-66.83,0.0,32.83");
	t_tuple p5 = validate_coordinates("-33.17,0.0,32.83");
	t_tuple p6 = validate_coordinates("-33,0.0,32");
	t_tuple p7 = validate_coordinates("-33,0.02");

	mu_check(compare_tuples(expected1, p1));
	mu_check(compare_tuples(expected2, p2));
	mu_check(compare_tuples(expected3, p3));
	mu_check(compare_tuples(expected4, p4));
	mu_check(compare_tuples(expected5, p5));
	mu_check(compare_tuples(expected6, p6));
	mu_check(p7 == NULL);

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

MU_TEST_SUITE(test_coordinates)
{
	MU_RUN_TEST(test_validate_coordinates);
}
