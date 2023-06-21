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
	set_transform(s, t);
	mu_check(compare_matrices(s->transform, t));

	free_matrix(t);
	free_matrix(s->transform);
	free(s->center);
	free(s);
}

MU_TEST_SUITE(test_spheres_transformation)
{
	MU_RUN_TEST(test_sphere_default_transformation);
	MU_RUN_TEST(test_changing_a_spheres_transformation);
}
