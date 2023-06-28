#include <minunit.h>
#include <minirt.h>

MU_TEST(test_that_a_point_light_has_a_position_and_intensity)
{
	t_tuple intensity = color(1, 1, 1);
	t_tuple position = point(0, 0, 0);
	t_light light = point_light(position, intensity);
	mu_check(compare_tuples(light.position, position));
	mu_check(compare_tuples(light.intensity, intensity));

	free(intensity);
	free(position);
	free(light.position);
	free(light.intensity)
	/*free(light);*/
}

MU_TEST(test_the_default_material)
{
	t_material m = material();
	t_tuple color_to_compare = color(1, 1, 1);
	mu_check(compare_tuples(m.color, color_to_compare));
	mu_check(m.ambient == 0.1);
	mu_check(m.diffuse == 0.9);
	mu_check(m.specular == 0.9);
	mu_check(m.shininess == 200.0);
	free(color_to_compare);
	free(m.color);
	/*free(material);*/
}

MU_TEST(test_that_a_sphere_may_be_assigned_a_material)
{
	t_sphere *s = sphere();
	t_material m = material();
	m.color = color(1, 1, 1);
	m.ambient = 1;
	s.material = m;
	/*check that s.material is the same as m, but how?*/

	/*lots of frees*/
}

MU_TEST(test_lighting_with_the_eye_between_the_light_and_the_surface)
{
	t_tuple p = point(0, 0, -10);
	t_tuple c = color(1, 1, 1);
	t_tuple eye_v = vector(0, 0, -1);
	t_tuple normal_v = vector(0, 0, -1);
	t_light light = point_light(p, c);
	t_color result = lighting(m, light, position, eye_v, normal_v);
	t_color expected = color(1.9, 1.9, 1.9);
	mu_check(compare_tuples(result, expected));

	free(eye_v);
	free(normal_v);
	free(result);
	free(expected);
	free(p);
	free(c);
	/*free(light);*/
}

MU_TEST(test_lighting_with_the_eye_between_light_and_surface_eye_offset_45_degrees)
{
	t_tuple p = point(0, 0, -10);
	t_tuple c = color(1, 1, 1);
	t_tuple eye_v = vector(0, sqrt(2) / 2, -sqrt(2) / 2);
	t_tuple normal_v = vector(0, 0, -1);
	t_light light = point_light(p, c);
	t_color result = lighting(m, light, position, eye_v, normal_v);
	t_color expected = color(1.0, 1.0, 1.0);
	mu_check(compare_tuples(result, expected));

	free(eye_v);
	free(normal_v);
	free(result);
	free(expected);
	free(p);
	free(c);
	/*free(light);*/
}

MU_TEST(test_lighting_with_the_eye_opposite_surface_light_offset_45_degrees)
{
	t_tuple p = point(0, 10, -10);
	t_tuple c = color(1, 1, 1);
	t_tuple eye_v = vector(0, 0, -1);
	t_tuple normal_v = vector(0, 0, -1);
	t_light light = point_light(p, c);
	t_color result = lighting(m, light, position, eye_v, normal_v);
	t_color expected = color(0.7364, 0.7364, 0.7364);
	mu_check(compare_tuples(result, expected));

	free(eye_v);
	free(normal_v);
	free(result);
	free(expected);
	free(p);
	free(c);
	/*free(light);*/
}

MU_TEST(test_lighting_with_the_eye_in_the_path_of_the_reflection_vector)
{
	t_tuple p = point(0, 10, -10);
	t_tuple c = color(1, 1, 1);
	t_tuple eye_v = vector(0, -sqrt(2) / 2, -sqrt(2) / 2);
	t_tuple normal_v = vector(0, 0, -1);
	t_light light = point_light(p, c);
	t_color result = lighting(m, light, position, eye_v, normal_v);
	t_color expected = color(1.6364, 1.6364, 1.6364);
	mu_check(compare_tuples(result, expected));

	free(eye_v);
	free(normal_v);
	free(result);
	free(expected);
	free(p);
	free(c);
	/*free(light);*/
}

MU_TEST(test_lighting_with_the_light_behind_the_surface)
{
	t_tuple p = point(0, 0, 10);
	t_tuple c = color(1, 1, 1);
	t_tuple eye_v = vector(0, 0, -1);
	t_tuple normal_v = vector(0, 0, -1);
	t_light light = point_light(p, c);
	t_color result = lighting(m, light, position, eye_v, normal_v);
	t_color expected = color(0.1, 0.1, 0.1);
	mu_check(compare_tuples(result, expected));

	free(eye_v);
	free(normal_v);
	free(result);
	free(expected);
	free(p);
	free(c);
	/*free(light);*/
}

MU_TEST_SUITE(test_the_phone_reflection_mode)
{
	MU_RUN_TEST(test_that_a_point_light_has_a_position_and_intensity);
	MU_RUN_TEST(test_the_default_material);
	MU_RUN_TEST(test_that_a_sphere_may_be_assigned_a_material);
	MU_RUN_TEST(test_lighting_with_the_eye_between_the_light_and_the_surface);
	MU_RUN_TEST(test_lighting_with_the_eye_between_light_and_surface_eye_offset_45_degrees);
	MU_RUN_TEST(test_lighting_with_the_eye_opposite_surface_light_offset_45_degrees);
	MU_RUN_TEST(test_lighting_with_the_eye_in_the_path_of_the_reflection_vector);
	MU_RUN_TEST(test_lighting_with_the_light_behind_the_surface);
}
