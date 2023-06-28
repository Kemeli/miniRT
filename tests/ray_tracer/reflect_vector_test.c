#include <minunit.h>
#include <minirt.h>

MU_TEST(test_reflecting_a_vector_approaching_at_45_degrees)
{
	t_tuple v = vector(1, -1, 0);
	t_tuple n = vector(0, 1, 0);
	t_tuple r = reflect(v, n);

	t_tuple expected = vector(1, 1, 0);
	mu_check(compare_tuples(expected, r));
	free(v);
	free(n);
	free(r);
	free(expected);
}

MU_TEST(test_reflecting_a_vector_off_a_slanted_surface)
{
	t_tuple v = vector(0, -1, 0);
	t_tuple n = vector(sqrt(2)/2, sqrt(2)/2, 0);
	t_tuple r = reflect(v, n);
	t_tuple expected = vector(1, 0, 0);

	mu_check(compare_tuples(expected, r));
	free(v);
	free(n);
	free(r);
	free(expected);
}

MU_TEST_SUITE(test_reflecting_vector)
{
	MU_RUN_TEST(test_reflecting_a_vector_approaching_at_45_degrees);
	MU_RUN_TEST(test_reflecting_a_vector_off_a_slanted_surface);
}
