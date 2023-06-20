#include <minirt.h>
#include <minunit.h>

MU_TEST(test_hit_intersection_sphere_all_positive_t)
{
	t_sphere *s = create_sphere();
	t_node *i1 = new_intersection(1, s);
	t_node *i2 = new_intersection(2, s);
	t_intersect *xs = NULL;
	xs = add_intersection_to_list(xs, i1);
	xs = add_intersection_to_list(xs, i2);

	t_node *i = hit(xs);
	mu_assert(i->t == 1, "hit->t != 1");

	free(s->center);
	free(s);
	free_list(xs);
}

MU_TEST_SUITE(test_hit_intersection)
{
	MU_RUN_TEST(test_hit_intersection_sphere_all_positive_t);
}
