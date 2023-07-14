#include <minirt.h>
#include <minunit.h>

MU_TEST(test_the_normal_on_a_sphere_at_a_point_on_the_x_axis)
{
	t_object	*object = ft_calloc(1, sizeof(t_object));
	t_tuple		p = point(1, 0, 0);
	t_tuple		esperado = vector(1, 0, 0);
	t_tuple		n;

	object->sphere = create_sphere();
	n = normal_at(object, p);
	mu_check(compare_tuples(esperado, n));

	free_sphere(object->sphere);
	free(p);
	free(esperado);
	free(n);
	free(object);
}

MU_TEST(test_the_normal_on_a_sphere_at_a_point_on_the_y_axis)
{
	t_object	*object = ft_calloc(1, sizeof(t_object));
	t_tuple		p = point(0, 1, 0);
	t_tuple		esperado = vector(0, 1, 0);
	t_tuple		n;

	object->sphere = create_sphere();
	n = normal_at(object, p);
	mu_check(compare_tuples(esperado, n));
	free(p);
	free_sphere(object->sphere);
	free(esperado);
	free(n);
	free(object);
}

MU_TEST(test_the_normal_on_a_sphere_at_a_point_on_the_z_axis)
{
	t_object	*object = ft_calloc(1, sizeof(t_object));
	t_tuple		p = point(0, 0, 1);
	t_tuple		esperado = vector(0, 0, 1);
	t_tuple		n;

	object->sphere = create_sphere();
	n = normal_at(object, p);
	mu_check(compare_tuples(esperado, n));

	free(p);
	free_sphere(object->sphere);
	free(esperado);
	free(n);
	free(object);
}

MU_TEST(test_the_normal_on_a_sphere_at_a_nonaxial_point)
{
	t_object	*object = ft_calloc(1, sizeof(t_object));
	t_tuple		p = point(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3);
	t_tuple		esperado = vector(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3);
	t_tuple		n;

	object->sphere = create_sphere();
	n = normal_at(object, p);
	mu_check(compare_tuples(esperado, n));

	free(p);
	free_sphere(object->sphere);
	free(esperado);
	free(n);
	free(object);
}

MU_TEST(test_the_normal_is_a_normalized_vector)
{
	t_object	*object = ft_calloc(1, sizeof(t_object));
	t_tuple		p = point(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3);
	t_tuple		esperado;
	t_tuple		n;

	object->sphere = create_sphere();
	n = normal_at(object, p);
	esperado = normalize(n);
	mu_check(compare_tuples(esperado, n));

	free(p);
	free_sphere(object->sphere);
	free(esperado);
	free(n);
	free(object);
}

MU_TEST(test_computing_the_normal_on_a_translated_sphere)
{
	t_object	*object = ft_calloc(1, sizeof(t_object));
	float		**t = translation(0, 1, 0);
	t_tuple		p = point(0, 1.70711f, -0.70711f);
	t_tuple		esperado;
	t_tuple		n;

	object->sphere = create_sphere();
	set_transform(&object->sphere, t);
	n = normal_at(object, p);
	esperado = vector(0, 0.70711f, -0.70711f);
	mu_check(compare_tuples(esperado, n));

	free(p);
	free_sphere(object->sphere);
	free_matrix(t);
	free(esperado);
	free(n);
	free(object);
}

MU_TEST(test_computing_the_normal_on_a_transformed_sphere)
{
	t_object *object = ft_calloc(1, sizeof(t_object));
	object->sphere = create_sphere();
	float **scaled = scaling(1, 0.5, 1);
	float **rotated = rotation_z(M_PI / 5);
	float **result = multiply_matrix(scaled, rotated);
	set_transform(&object->sphere, result);
	t_tuple p = point(0, sqrt(2)/2, -sqrt(2)/2);
	t_tuple n = normal_at(object, p);
	t_tuple expected = vector(0, 0.97014f, -0.24254f);
	mu_check(compare_tuples(expected, n));

	free(p);
	free_sphere(object->sphere);
	free_matrix(scaled);
	free_matrix(rotated);
	free_matrix(result);
	free(expected);
	free(n);
	free(object);
}

MU_TEST_SUITE(test_normal_at)
{
	MU_RUN_TEST(test_the_normal_on_a_sphere_at_a_point_on_the_x_axis);
	MU_RUN_TEST(test_the_normal_on_a_sphere_at_a_point_on_the_y_axis);
	MU_RUN_TEST(test_the_normal_on_a_sphere_at_a_point_on_the_z_axis);
	MU_RUN_TEST(test_the_normal_on_a_sphere_at_a_nonaxial_point);
	MU_RUN_TEST(test_the_normal_is_a_normalized_vector);
	MU_RUN_TEST(test_computing_the_normal_on_a_translated_sphere);
	MU_RUN_TEST(test_computing_the_normal_on_a_transformed_sphere);
}
