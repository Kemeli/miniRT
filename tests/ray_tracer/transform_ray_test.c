#include <minirt.h>
#include <minunit.h>

MU_TEST(test_translating_ray)
{
	t_tuple p = point(1, 2, 3);
	t_tuple v = vector(0, 1, 0);
	t_ray *r = create_ray(p, v);
	double **m = translation(3, 4, 5);
	t_ray *r2 = transform_ray(r, m);
	t_tuple p1 = point(4, 6, 8);
	t_tuple v1 = vector(0, 1, 0);
	mu_check(compare_tuples(r2->origin, p1));
	mu_check(compare_tuples(r2->direction, v1));

	free(p);
	free(v);
	free(p1);
	free(v1);
	free(r2->direction);
	free(r2->origin);
	free(r2);
	free(r);
	free_matrix(m);
}

MU_TEST(test_scaling_ray)
{
	t_tuple p = point(1, 2, 3);
	t_tuple v = vector(0, 1, 0);
	t_ray *r = create_ray(p, v);
	double **m = scaling(2, 3, 4);
	t_ray *r2 = transform_ray(r, m);
	t_tuple p1 = point(2, 6, 12);
	t_tuple v1 = vector(0, 3, 0);
	mu_check(compare_tuples(r2->origin, p1));
	mu_check(compare_tuples(r2->direction, v1));

	free(p);
	free(v);
	free(p1);
	free(v1);
	free(r2->direction);
	free(r2->origin);
	free(r2);
	free(r);
	free_matrix(m);
}

MU_TEST_SUITE(test_transform_ray)
{
	MU_RUN_TEST(test_translating_ray);
	MU_RUN_TEST(test_scaling_ray);
}
