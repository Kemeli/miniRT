#include <minirt.h>
#include <minunit.h>

MU_TEST(test_hit_intersection_sphere_all_positive_t)
{
	t_object *object;
	object = create_object('s');

	t_list *i1 = new_intersection(1, object);
	t_list *i2 = new_intersection(2, object);
	t_intersect *xs = ft_calloc(1, sizeof(t_intersect));
	ft_lstadd_back(&i1, i2);
	xs->head = i1;

	t_node *i = hit(xs);
	mu_assert(i->t == 1, "hit->t != 1");

	free_intersections(xs);
	free_object(object);
}

MU_TEST(test_hit_intersection_sphere_has_negative_t)
{
	t_object *object;
	object = create_object('s');
	t_list *i1 = new_intersection(-1, object);
	t_list *i2 = new_intersection(1, object);
	t_intersect *xs = ft_calloc(1, sizeof(t_intersect));
	ft_lstadd_back(&i1, i2);
	xs->head = i1;

	t_node *i = hit(xs);
	mu_assert(i->t == 1, "hit->t != -1");

	free_object(object);
	free_intersections(xs);
}

MU_TEST(test_hit_intersection_sphere_all_negative_t)
{
	t_object *object;
	object = create_object('s');
	t_list *i1 = new_intersection(-2, object);
	t_list *i2 = new_intersection(-1, object);
	t_intersect *xs = ft_calloc(1, sizeof(t_intersect));
	ft_lstadd_back(&i1, i2);
	xs->head = i1;

	t_node *i = hit(xs);
	mu_assert(i == NULL, "hit != NULL");

	free_object(object);
	free_intersections(xs);
}

MU_TEST(test_hit_intersection_is_always_lowest_nonnegative_t)
{
	t_object *object;
	object = create_object('s');
	t_list *i1 = new_intersection(5,object);
	t_list *i2 = new_intersection(7,object);
	t_list *i3 = new_intersection(-3,object);
	t_list *i4 = new_intersection(2,object);
	t_intersect *xs = ft_calloc(1, sizeof(t_intersect));
	ft_lstadd_back(&i1, i2);
	ft_lstadd_back(&i1, i3);
	ft_lstadd_back(&i1, i4);
	xs->head = i1;

	t_node *i = hit(xs);
	mu_assert(i->t == 2, "hit->t != 2");

	free_object(object);
	free_intersections(xs);
}

MU_TEST_SUITE(test_hit_intersection)
{
	MU_RUN_TEST(test_hit_intersection_sphere_all_positive_t);
	MU_RUN_TEST(test_hit_intersection_sphere_has_negative_t);
	MU_RUN_TEST(test_hit_intersection_sphere_all_negative_t);
	MU_RUN_TEST(test_hit_intersection_is_always_lowest_nonnegative_t);
}
