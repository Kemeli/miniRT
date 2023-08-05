#include <minirt.h>
#include <minunit.h>

MU_TEST(test_the_normal_on_an_object_at_a_point_on_the_x_axis)
{
	t_object	*object = create_object('s');
	t_tuple		p = point(1, 0, 0);
	t_tuple		esperado = vector(1, 0, 0);
	t_tuple		n;

	n = normal_at(object, p);
	mu_check(compare_tuples(esperado, n));

	free_object(object);
	free(p);
	free(esperado);
	free(n);
}

MU_TEST(test_the_normal_on_an_object_at_a_point_on_the_y_axis)
{
	t_object	*object = create_object('s');
	t_tuple		p = point(0, 1, 0);
	t_tuple		esperado = vector(0, 1, 0);
	t_tuple		n;

	n = normal_at(object, p);
	mu_check(compare_tuples(esperado, n));
	free(p);
	free_object(object);
	free(esperado);
	free(n);
}

MU_TEST(test_the_normal_on_an_object_at_a_point_on_the_z_axis)
{
	t_object	*object = create_object('s');
	t_tuple		p = point(0, 0, 1);
	t_tuple		esperado = vector(0, 0, 1);
	t_tuple		n;

	n = normal_at(object, p);
	mu_check(compare_tuples(esperado, n));

	free(p);
	free_object(object);
	free(esperado);
	free(n);
}

MU_TEST(test_the_normal_on_an_object_at_a_nonaxial_point)
{
	t_object	*object = create_object('s');
	t_tuple		p = point(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3);
	t_tuple		esperado = vector(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3);
	t_tuple		n;

	n = normal_at(object, p);
	mu_check(compare_tuples(esperado, n));

	free(p);
	free_object(object);
	free(esperado);
	free(n);
}

MU_TEST(test_the_normal_is_a_normalized_vector)
{
	t_object	*object = create_object('s');
	t_tuple		p = point(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3);
	t_tuple		esperado;
	t_tuple		n;

	n = normal_at(object, p);
	esperado = normalize(n);
	mu_check(compare_tuples(esperado, n));

	free(p);
	free_object(object);
	free(esperado);
	free(n);
}

MU_TEST(test_computing_the_normal_on_a_translated_object)
{
	t_object	*o = create_object('s');
	float		**t = translation(0, 1, 0);
	t_tuple		p = point(0, 1.70711f, -0.70711f);
	t_tuple		esperado;
	t_tuple		n;

	set_transform(&o, t);
	n = normal_at(o, p);
	esperado = vector(0, 0.70711f, -0.70711f);
	mu_check(compare_tuples(esperado, n));

	free(p);
	free_object(o);
	free_matrix(t);
	free(esperado);
	free(n);
}

MU_TEST(test_computing_the_normal_on_a_transformed_object)
{
	t_object *o = create_object('s');

	float **scaled = scaling(1, 0.5, 1);
	float **rotated = rotation_z(M_PI / 5);
	float **result = multiply_matrix(scaled, rotated);
	set_transform(&o, result);
	t_tuple p = point(0, sqrt(2)/2, -sqrt(2)/2);
	t_tuple n = normal_at(o, p);
	t_tuple expected = vector(0, 0.97014f, -0.24254f);
	mu_check(compare_tuples(expected, n));

	free(p);
	free_object(o);
	free_matrix(scaled);
	free_matrix(rotated);
	free_matrix(result);
	free(expected);
	free(n);
}

MU_TEST_SUITE(test_normal_at)
{
	MU_RUN_TEST(test_the_normal_on_an_object_at_a_point_on_the_x_axis);
	MU_RUN_TEST(test_the_normal_on_an_object_at_a_point_on_the_y_axis);
	MU_RUN_TEST(test_the_normal_on_an_object_at_a_point_on_the_z_axis);
	MU_RUN_TEST(test_the_normal_on_an_object_at_a_nonaxial_point);
	MU_RUN_TEST(test_the_normal_is_a_normalized_vector);
	MU_RUN_TEST(test_computing_the_normal_on_a_translated_object);
	MU_RUN_TEST(test_computing_the_normal_on_a_transformed_object);
}
