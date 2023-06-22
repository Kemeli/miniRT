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
	free(s);
}

MU_TEST(test_intersecting_a_scaled_sphere_with_a_ray)
{
	t_sphere	*s;
	t_ray		*r;
	t_tuple		p;
	t_tuple		v;
	t_intersect	*xs;
	float		**scale;

	p = point(0, 0, -5);
	v = vector(0, 0, 1);
	r = create_ray(p, v);
	s = create_sphere();
	scale = scaling(2, 2, 2);
	set_transform(&s, scale);
	xs = intersect_sphere(s, r);

	mu_assert_int_eq(2, xs->count);
	mu_assert_double_eq(3, xs->head->t);
	mu_assert_double_eq(7, xs->head->next->t);

	free_matrix(s->transform);
	free(s->center);
	free(s);
	free(r);
	free(v);
	free(p);
	free_list(xs);
	free_matrix(scale);
}

MU_TEST_SUITE(test_spheres_transformation)
{
	MU_RUN_TEST(test_sphere_default_transformation);
	MU_RUN_TEST(test_changing_a_spheres_transformation);
	MU_RUN_TEST(test_intersecting_a_scaled_sphere_with_a_ray);
}
