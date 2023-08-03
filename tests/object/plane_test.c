#include <minirt.h>
#include <minunit.h>

MU_TEST(test_plane_normal_at)
{
	t_object *o = create_object('p');

	t_tuple p1 = point(0, 0, 0);
	t_tuple p2 = point(10, 0, -10);
	t_tuple p3 = point(-5, 0, 150);

	t_tuple n1 = local_normal_at(o, p1);
	t_tuple n2 = local_normal_at(o, p2);
	t_tuple n3 = local_normal_at(o, p3);

	t_tuple expected = vector(0, 1, 0);

	mu_check(compare_tuples(n1, expected));
	mu_check(compare_tuples(n2, expected));
	mu_check(compare_tuples(n3, expected));


	free_object(o);
	free(p1);
	free(p2);
	free(p3);
	free(n1);
	free(n2);
	free(n3);
	free(expected);
}

MU_TEST_SUITE(test_plane)
{
	MU_RUN_TEST(test_plane_normal_at);
}
