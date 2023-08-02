#include <minirt.h>
#include <minunit.h>

MU_TEST(test_intersecting_a_scaled_shape_with_a_ray)
{
	t_ray		*r;
	t_tuple		p;
	t_tuple		v;
	float		**scale;

	p = point(0, 0, -5);
	v = vector(0, 0, 1);
	r = create_ray(p, v);

	scale = scaling(2, 2, 2);
	t_object *o = create_object('s');
	set_transform(&o, scale);
	t_intersect *xs = intersect(&o, r);

	t_tuple expected_origin = point(0, 0, -2.5);
	t_tuple expected_direction = vector(0, 0, 0.5);

	mu_check(compare_tuples(o->saved_ray->origin, expected_origin));
	mu_check(compare_tuples(o->saved_ray->direction, expected_direction));


	free_matrix(scale);
	free_ray(r);
	free_object(o);
	free_intersections(xs);
	free(expected_origin);
	free(expected_direction);
}

MU_TEST(test_intersecting_a_translated_shape_with_a_ray)
{
	t_ray		*r;
	t_tuple		p;
	t_tuple		v;
	float		**scale;

	p = point(0, 0, -5);
	v = vector(0, 0, 1);
	r = create_ray(p, v);

	t_matrix translate = translation(5, 0, 0);
	t_object *o = create_object('s');
	set_transform(&o, translate);
	t_intersect *xs = intersect(&o, r);

	t_tuple expected_origin = point(-5, 0, -5);
	t_tuple expected_direction = vector(0, 0, 1);

	mu_check(compare_tuples(o->saved_ray->origin, expected_origin));
	mu_check(compare_tuples(o->saved_ray->direction, expected_direction));

	free_matrix(translate);
	free_ray(r);
	free_object(o);
	free_intersections(xs);
	free(expected_origin);
	free(expected_direction);
}

MU_TEST_SUITE(test_shapes)
{
	MU_RUN_TEST(test_intersecting_a_scaled_shape_with_a_ray);
	MU_RUN_TEST(test_intersecting_a_translated_shape_with_a_ray);
}
