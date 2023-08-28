#include <minunit.h>
#include <minirt.h>

#include <time.h>

MU_TEST(test_constructing_a_ray_through_the_center_of_the_canvas)
{

	t_camera	*c = camera(201, 101, M_PI / 2);
	clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();  // Record the start time

	t_ray		*r = ray_for_pixel(c, 100, 50);

    end_time = clock();  // Record the end time

    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;  // Calculate the time used in seconds

    printf("Time taken by the function: %f seconds\n", cpu_time_used);

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
/*
t_tuple	pixel_at(t_image *image, int x, int y)
{
	int pixel_offset = (y * image->line_len) + (x * (image->bpp / 8));
	t_tuple	pixel_color = color(5, 5, 5);

	pixel_color[0] = image->addr[pixel_offset + 0] / 255.0;
	pixel_color[1] = image->addr[pixel_offset + 1] / 255.0;
	pixel_color[2] = image->addr[pixel_offset + 2] / 255.0;
	pixel_color[3] = 0;

	printf("pixel_color att: %f %f %f\n", pixel_color[0], pixel_color[1], pixel_color[2]);
	// printf("x e y att: %d %d\n", x, y);
	// printf("pixel_offset att: %d\n", pixel_offset);

	return (pixel_color);
}

MU_TEST(test_rendering_a_world_with_a_camera)
{
	t_world		*w = default_world();
	t_camera	*c = camera(11, 11, M_PI / 2);
	t_tuple		from = point(0, 0, -5);
	t_tuple		to = point(0, 0, 0);
	t_tuple		up = vector(0, 1, 0);

	t_data *data =ft_calloc(1, sizeof(t_data));

	free_matrix(c->transform);
	c->transform = view_transform(from, to, up);
	data->c = c;
	data->w = w;
	t_image		*image = render(data);
	// printf("\nimage: %f %f %f\n", image->addr[240 + 0] / 255.0, image->addr[240 + 1] / 255.0, image->addr[240 + 2] / 255.0);
	t_tuple		pixel_color = pixel_at(image, 5,5);

	// printf("\n\npixel_color: %f %f %f\n\n", pixel_color[0], pixel_color[1], pixel_color[2]);

	mu_check(compare_tuples(pixel_color, color(0.2855, 0.47583, 0.38066)));
	free_camera(c);
}
*/
MU_TEST_SUITE(test_ray_for_pixel)
{
	MU_RUN_TEST(test_constructing_a_ray_through_the_center_of_the_canvas);
	MU_RUN_TEST(test_constructing_a_ray_through_a_corner_of_the_canvas);
	MU_RUN_TEST(test_constructing_a_ray_when_the_camera_is_transformed);
	// MU_RUN_TEST(test_rendering_a_world_with_a_camera);
}
