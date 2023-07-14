#include <minirt.h>
#include <minunit.h>

MU_TEST(test_sphere_default_transformation)
{
	t_sphere *s = create_sphere();
	float **expected = identity_matrix(4);
	mu_check(compare_matrices(s->transform, expected));

	free_matrix(expected);
	free_matrix(s->transform);
	free(s->center);
	free(s->material->color);
	free(s->material);
	free(s);
}

MU_TEST(test_changing_a_spheres_transformation)
{
	t_sphere	*s;
	float		**t;

	s = create_sphere();
	t = translation(2, 3, 4);
	set_transform(&s, t);
	mu_check(compare_matrices(s->transform, t));

	free_matrix(t);
	free_matrix(s->transform);
	free(s->center);
	free(s->material->color);
	free(s->material);
	free(s);
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
	t_object *object = ft_calloc(1, sizeof(t_object));
	object->sphere = create_sphere();
	set_transform(&object->sphere, scale);
	t_intersect *xs = intersect_sphere(object, r);
	mu_assert_int_eq(2, xs->count);
	mu_assert_double_eq(3, ((t_node*)xs->head->content)->t);
	mu_assert_double_eq(7, ((t_node*)xs->head->next->content)->t);

	free(r);
	free(v);
	free(p);
	free_intersections(xs);
	free_matrix(scale);

	free_matrix(object->sphere->transform);
	free(object->sphere->material->color);
	free (object->sphere->material);
	free(object->sphere->center);
	free(object->sphere);
	free(object);
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
	t_object *object = ft_calloc(1, sizeof(t_object));
	object->sphere = create_sphere();
	set_transform(&object->sphere, t);
	t_intersect *xs = intersect_sphere(object, r);
	mu_check(compare_matrices(object->sphere->transform, t));

	free_matrix(t);
	free_intersections(xs);
	free(r);
	free(p);
	free(v);

	free_matrix(object->sphere->transform);
	free(object->sphere->material->color);
	free (object->sphere->material);
	free(object->sphere->center);
	free(object->sphere);
	free(object);
}

MU_TEST_SUITE(test_spheres_transformation)
{
	MU_RUN_TEST(test_sphere_default_transformation);
	MU_RUN_TEST(test_changing_a_spheres_transformation);
	MU_RUN_TEST(test_intersecting_a_scaled_sphere_with_a_ray);
	MU_RUN_TEST(test_intersecting_a_translated_sphere_with_a_ray);
}
