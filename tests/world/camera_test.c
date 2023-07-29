#include <minunit.h>
#include <minirt.h>

MU_TEST(test_constructing_a_camera)
{
	float	hsize = 160;
	float	vsize = 120;
	float	field_of_view = M_PI / 2;

	t_camera	*c = camera(hsize, vsize, field_of_view);
	mu_check(c->hsize == 160);
	mu_check(c->vsize == 120);

	mu_check(compare_floats(field_of_view, M_PI / 2));

	t_matrix	identity = identity_matrix(4);
	mu_check(compare_matrices(c->transform, identity));

	free_matrix(identity);
	free_camera(c);
}

MU_TEST(test_the_pixel_size_for_a_horizontal_canvas)
{
	t_camera	*c = camera(200, 125, M_PI / 2);
	mu_check(compare_floats(c->pixel_size, 0.01));
	free_camera(c);
}

MU_TEST(test_the_pixel_size_for_a_vertical_canvas)
{
	t_camera	*c = camera(125, 200, M_PI / 2);
	mu_check(compare_floats(c->pixel_size, 0.01));
	free_camera(c);
}

MU_TEST_SUITE(test_implementing_a_camera)
{
	MU_RUN_TEST(test_constructing_a_camera);
	MU_RUN_TEST(test_the_pixel_size_for_a_horizontal_canvas);
	MU_RUN_TEST(test_the_pixel_size_for_a_vertical_canvas);
}
