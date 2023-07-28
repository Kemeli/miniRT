#include <minirt.h>
#include <stdio.h>

MU_TEST(test_there_is_no_shadow_when_nothing_is_collinear_with_point_and_light)
{
	t_world *w = default_world();
	t_tuple p = point(0, 10, 0);
	char result = is_shadowed(w, p);

	mu_assert_int_eq(FALSE, result);

	free_world(w);
}

MU_TEST(test_the_shadow_when_an_object_is_between_the_point_and_the_light)
{
	t_world *w = default_world();
	t_tuple p = point(10, -10, 10);
	char result = is_shadowed(w, p);

	mu_assert_int_eq(TRUE, result);

	free_world(w);
}

MU_TEST(test_there_is_no_shadow_when_an_object_is_behind_the_light)
{
	t_world *w = default_world();
	t_tuple p = point(-20, 20, -20);
	char result = is_shadowed(w, p);

	mu_assert_int_eq(FALSE, result);

	free_world(w);
}

MU_TEST(test_there_is_no_shadow_when_an_object_is_behind_the_point)
{
	t_world *w = default_world();
	t_tuple p = point(-2, 2, -2);
	char result = is_shadowed(w, p);

	mu_assert_int_eq(FALSE, result);

	free_world(w);
}

MU_TEST_SUITE(test_shadows)
{
	MU_RUN_TEST(test_there_is_no_shadow_when_nothing_is_collinear_with_point_and_light);
	MU_RUN_TEST(test_the_shadow_when_an_object_is_between_the_point_and_the_light);
	MU_RUN_TEST(test_there_is_no_shadow_when_an_object_is_behind_the_light);
	MU_RUN_TEST(test_there_is_no_shadow_when_an_object_is_behind_the_point);
}
