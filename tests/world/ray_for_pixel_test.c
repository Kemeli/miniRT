#include <minunit.h>
#include <minirt.h>

MU_TEST(test_constructing_a_ray_through_the_center_of_the_canvas)
{
	t_camera	*c = camera(201, 101, M_PI / 2);
	t_ray		*r = ray_for_pixel(c, 100, 50);

	t_tuple		p = point(0, 0, 0);
	t_tuple		v = vector(0, 0, -1);

	mu_check(compare_tuples(r->origin, p));
	mu_check(compare_tuples(r->direction, v));

	free_camera(c);
	free_ray(r);
	free(p);
	free(v);
}

MU_TEST(test_constructing_a_ray_through_a_corner_of_the_canvas)
{
	t_camera	*c = camera(201, 101, M_PI / 2);
	t_matrix	rotation = rotation_y(M_PI / 4);
	t_matrix	transl = translation(0, -2, 5);
	free_matrix(c->transform);
	c->transform = multiply_matrix(rotation, transl);
	t_ray		*r = ray_for_pixel(c, 100, 50);
	t_tuple		p = point(0, 2, -5);
	t_tuple		v = vector(sqrt(2) / 2, 0, -sqrt(2) / 2);

	mu_check(compare_tuples(r->origin, p));
	mu_check(compare_tuples(r->direction, v));

	free_camera(c);
	free_matrix(rotation);
	free_matrix(transl);
	free_ray(r);
	free(p);
	free(v);
}

MU_TEST(test_constructing_a_ray_when_the_camera_is_transformed)
{
	t_camera	*c = camera(201, 101, M_PI / 2);
	t_ray		*r = ray_for_pixel(c, 0, 0);

	t_tuple		p = point(0, 0, 0);
	t_tuple		v = vector(0.66519, 0.33259, -0.66851);

	mu_check(compare_tuples(r->origin, p));
	mu_check(compare_tuples(r->direction, v));

	free_camera(c);
	free_ray(r);
	free(p);
	free(v);
}

MU_TEST(test_rendering_a_world_with_a_camera)
{
	t_world		*w = default_world();
	t_camera	*c = camera(11, 11, M_PI / 2);
	t_ray		*r = ray_for_pixel(c, 0, 0);
	t_tuple		from = point(0, 0, -5);
	t_tuple		to = point(0, 0, 0);
	t_tuple		up = vector(0, 1, 0);
	t_img		image;

	free_matrix(c->transform);
	c->transform = view_transform(from, to, up);
	image = render(c, w);

	mu_check(compare_tuples(r->origin, p));
	mu_check(compare_tuples(r->direction, v));

	free_camera(c);
	free_ray(r);
}
MU_TEST_SUITE(test_ray_for_pixel)
{
	MU_RUN_TEST(test_constructing_a_ray_through_the_center_of_the_canvas);
	MU_RUN_TEST(test_constructing_a_ray_through_a_corner_of_the_canvas);
	MU_RUN_TEST(test_constructing_a_ray_when_the_camera_is_transformed);
	MU_RUN_TEST(test_rendering_a_world_with_a_camera);
}
