#include <minirt.h>
#include <minunit.h>

MU_TEST(test_a_ray_misses_a_cylinder)
{
	t_object *o = create_object('c');

	t_tuple orgin = point(1, 0, 0);
	t_tuple direction = vector(0, 1, 0);
	t_tuple norm_direction = normalize(direction);
	t_ray *r = create_ray(orgin, norm_direction);

	t_intersect *xs = intersect(&o, r);
	mu_check(xs->count == 0);

	free(direction);
	free_intersections(xs);
	free_ray(r);
	free_object(o);
}

MU_TEST(test_a_ray_misses_a_cylinder2)
{
	t_object *o = create_object('c');

	t_tuple orgin = point(0, 0, 0);
	t_tuple direction = vector(0, 1, 0);
	t_tuple norm_direction = normalize(direction);
	t_ray *r = create_ray(orgin, norm_direction);

	t_intersect *xs = intersect(&o, r);
	mu_check(xs->count == 0);

	free(direction);
	free_intersections(xs);
	free_ray(r);
	free_object(o);
}

MU_TEST(test_a_ray_misses_a_cylinder3)
{
	t_object *o = create_object('c');

	t_tuple orgin = point(0, 0, -5);
	t_tuple direction = vector(1, 1, 1);
	t_tuple norm_direction = normalize(direction);
	t_ray *r = create_ray(orgin, norm_direction);

	t_intersect *xs = intersect(&o, r);
	mu_check(xs->count == 0);

	free(direction);
	free_intersections(xs);
	free_ray(r);
	free_object(o);
}

MU_TEST(test_a_ray_strikes_a_cylinder)
{
	t_object *o = create_object('c');

	t_tuple orgin = point(1, 0, -5);
	t_tuple direction = vector(0, 0, 1);
	t_tuple norm_direction = normalize(direction);
	t_ray *r = create_ray(orgin, norm_direction);

	t_intersect *xs = intersect(&o, r);
	mu_check(xs->count == 2);
	mu_check(((t_node *)xs->head->content)->t == 5);
	mu_check(((t_node *)xs->head->next->content)->t == 5);

	free(direction);
	free_intersections(xs);
	free_ray(r);
	free_object(o);
}

MU_TEST(test_a_ray_strikes_a_cylinder2)
{
	t_object *o = create_object('c');

	t_tuple orgin = point(0, 0, -5);
	t_tuple direction = vector(0, 0, 1);
	t_tuple norm_direction = normalize(direction);
	t_ray *r = create_ray(orgin, norm_direction);

	t_intersect *xs = intersect(&o, r);
	mu_check(xs->count == 2);
	mu_check(((t_node *)xs->head->content)->t == 4);
	mu_check(((t_node *)xs->head->next->content)->t == 6);

	free(direction);
	free_intersections(xs);
	free_ray(r);
	free_object(o);
}

MU_TEST(test_a_ray_strikes_a_cylinder3)
{
	t_object *o = create_object('c');

	t_tuple orgin = point(0.5, 0, -5);
	t_tuple direction = vector(0.1, 1, 1);
	t_tuple norm_direction = normalize(direction);
	t_ray *r = create_ray(orgin, norm_direction);

	t_intersect *xs = intersect(&o, r);
	mu_check(xs->count == 2);

	mu_check(compare_floats(((t_node *)xs->head->content)->t, 6.8080)); // 6.80798
	mu_check(compare_floats(((t_node *)xs->head->next->content)->t, 7.0887));

	free(direction);
	free_intersections(xs);
	free_ray(r);
	free_object(o);
}

MU_TEST_SUITE(test_cylinder)
{
	MU_RUN_TEST(test_a_ray_misses_a_cylinder);
	MU_RUN_TEST(test_a_ray_misses_a_cylinder2);
	MU_RUN_TEST(test_a_ray_misses_a_cylinder3);

	MU_RUN_TEST(test_a_ray_strikes_a_cylinder);
	MU_RUN_TEST(test_a_ray_strikes_a_cylinder2);
	MU_RUN_TEST(test_a_ray_strikes_a_cylinder3);
}
