#include <minirt.h>
#include <minunit.h>

MU_TEST(test_object_default_transformation)
{
	t_object *o = create_object('s');
	float **expected = identity_matrix(4);
	mu_check(compare_matrices(o->transform, expected));

	free_matrix(expected);
	free_object(o);
}

MU_TEST(test_changing_an_object_transformation)
{
	float **t;
	t_object *o = create_object('s');
	t = translation(2, 3, 4);
	set_transform(&o, t);
	mu_check(compare_matrices(o->transform, t));

	free_matrix(t);
	free_object(o);
}

MU_TEST(test_intersecting_a_scaled_sphere_with_a_ray)
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
	mu_assert_int_eq(2, xs->count);
	mu_assert_double_eq(3, ((t_node*)xs->head->content)->t);
	mu_assert_double_eq(7, ((t_node*)xs->head->next->content)->t);

	free(r);
	free(v);
	free(p);
	free_intersections(xs);
	free_matrix(scale);
	free_object(o);
}

MU_TEST(test_intersecting_a_translated_sphere_with_a_ray)
{
	t_ray		*r;
	t_tuple		p;
	t_tuple		v;
	float		**t;

	t = translation(5, 0, 0);
	p = point(0, 0, -5);
	v = vector(0, 0, 1);
	r = create_ray(p, v);
	t_object *o = create_object('s');
	set_transform(&o, t);
	t_intersect *xs = intersect(&o, r);
	mu_check(compare_matrices(o->transform, t));

	free_matrix(t);
	free_intersections(xs);
	free(r);
	free(p);
	free(v);
	free_object(o);
}

MU_TEST_SUITE(test_spheres_transformation)
{
	MU_RUN_TEST(test_object_default_transformation);
	MU_RUN_TEST(test_changing_an_object_transformation);
	MU_RUN_TEST(test_intersecting_a_scaled_sphere_with_a_ray);
	MU_RUN_TEST(test_intersecting_a_translated_sphere_with_a_ray);
}
