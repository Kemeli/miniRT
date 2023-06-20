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

MU_TEST(test_hit_intersection_sphere_has_negative_t)
{

	t_sphere *s = create_sphere();
	t_node *i1 = new_intersection(-1, s);
	t_node *i2 = new_intersection(1, s);
	t_intersect *xs = NULL;
	xs = add_intersection_to_list(xs, i1);
	xs = add_intersection_to_list(xs, i2);

	t_node *i = hit(xs);
	mu_assert(i->t == 1, "hit->t != 1");

	free(s->center);
	free(s);
	free_list(xs);
}

MU_TEST(test_hit_intersection_sphere_all_negative_t)
{
	t_sphere *s = create_sphere();
	t_node *i1 = new_intersection(-2, s);
	t_node *i2 = new_intersection(-1, s);
	t_intersect *xs = NULL;
	xs = add_intersection_to_list(xs, i1);
	xs = add_intersection_to_list(xs, i2);

	t_node *i = hit(xs);
	mu_assert(i == NULL, "hit != NULL");

	free(s->center);
	free(s);
	free_list(xs);
}

MU_TEST(test_hit_intersection_is_always_lowest_nonnegative_t)
{
	t_sphere *s = create_sphere();
	t_node *i1 = new_intersection(5, s);
	t_node *i2 = new_intersection(7, s);
	t_node *i3 = new_intersection(-3, s);
	t_node *i4 = new_intersection(2, s);
	t_intersect *xs = NULL;
	xs = add_intersection_to_list(xs, i1);
	xs = add_intersection_to_list(xs, i2);
	xs = add_intersection_to_list(xs, i3);
	xs = add_intersection_to_list(xs, i4);

	t_node *i = hit(xs);
	mu_assert(i->t == 2, "hit->t != 2");

	free(s->center);
	free(s);
	free_list(xs);
}

MU_TEST_SUITE(test_hit_intersection)
{
	MU_RUN_TEST(test_hit_intersection_sphere_all_positive_t);
	MU_RUN_TEST(test_hit_intersection_sphere_has_negative_t);
	MU_RUN_TEST(test_hit_intersection_sphere_all_negative_t);
	MU_RUN_TEST(test_hit_intersection_is_always_lowest_nonnegative_t);
}
