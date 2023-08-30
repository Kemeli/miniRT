#include <minirt.h>
#include <minunit.h>

MU_TEST(test_precomputing_the_state_of_an_intersection)
{
	t_object	*o = create_object('s');
	t_tuple		p = point(0, 0, -5);
	t_tuple		p_check = point(0, 0, -1);
	t_tuple		v = vector(0, 0, 1);
	t_tuple		v_check = vector(0, 0, -1);
	t_ray		*r = create_ray(p, v);

	t_node	*i = new_intersection(4, o);
	t_comps	*comps = prepare_computations(i, r);

	mu_check(i->t == comps->t);
	mu_check(compare_pointers(i->object, comps->object));
	mu_check(compare_tuples(p_check, comps->point));
	mu_check(compare_tuples(v_check, comps->eye));
	mu_check(compare_tuples(v_check, comps->normal));

	free_object(o);
	free_comps(comps);
	free(p_check);
	free(v_check);
	ft_lstclear(&i, free);
	free_ray(r);
}

MU_TEST(test_the_hit_when_an_intersection_occurs_on_the_outside)
{
	t_object	*o = create_object('s');
	t_tuple		p = point(0, 0, -5);
	t_tuple		v = vector(0, 0, 1);
	t_ray		*r = create_ray(p, v);
	t_tuple		p_check = point(0, 0, -1);
	t_tuple		v_check = vector(0, 0, -1);

	t_node	*i = new_intersection(4, o);
	t_comps	*comps = prepare_computations(i, r);

	mu_check(comps->inside == FALSE);

	free_object(o);
	free_comps(comps);
	free(p_check);
	free(v_check);
	ft_lstclear(&i, free);
	free_ray(r);
}

MU_TEST(test_the_hit_when_an_intersection_occurs_on_the_inside)
{
	t_tuple		p = point(0, 0, 0);
	t_tuple		v = vector(0, 0, 1);
	t_ray		*r = create_ray(p, v);

	t_object	*o = create_object('s');
	t_node		*i = new_intersection(1, o);
	t_comps		*comps = prepare_computations(i, r);

	t_tuple		p_expected = point(0, 0, 1);
	t_tuple		v_expected = vector(0, 0, -1);

	mu_check(comps->inside == TRUE);
	mu_check(compare_tuples(p_expected, comps->point));
	mu_check(compare_tuples(v_expected, comps->eye));
	mu_check(compare_tuples(v_expected, comps->normal));

	free_object(o);
	free_comps(comps);
	free(p_expected);
	free(v_expected);
	ft_lstclear(&i, free);
	free_ray(r);
}

MU_TEST(test_shading_an_intersection)
{
	t_world		*w = default_world();

	t_tuple		r_origin = point(0, 0, -5);
	t_tuple		r_direction = vector(0, 0, 1);
	t_ray		*r = create_ray(r_origin, r_direction);

	t_node		*i = new_intersection(4, w->head->object);

	t_comps		*comps = prepare_computations(i, r);
	t_tuple		c = shade_hit(w, comps);
	t_tuple		expected = color(0.38066, 0.47583, 0.2855);

	mu_check(compare_tuples(expected, c));

	free(expected);
	free(c);
	ft_lstclear(&i, free);
	free_world(w);
	free_comps(comps);
	free_ray(r);
}

MU_TEST(test_shading_an_intersection_from_the_inside)
{
	t_world		*w = default_world();
	free(w->light->position);
	free(w->light->intensity);
	free(w->light);
	t_tuple		p = point(0, 0.25, 0);
	t_tuple		c = color(1, 1, 1);
	w->light = point_light(p, c);

	t_tuple		r_origin = point(0, 0, 0);
	t_tuple		r_direction = vector(0, 0, 1);
	t_ray		*r = create_ray(r_origin, r_direction);
	t_node		*i = new_intersection(0.5, w->head->next->object);
	t_comps		*comps = prepare_computations(i, r);

	t_tuple		c_shade_hit = shade_hit(w, comps);
	t_tuple		expected = color(0.90498, 0.90498, 0.90498);

	mu_check(compare_tuples(expected, c_shade_hit));

	free(expected);
	free(c_shade_hit);
	free_ray(r);
	ft_lstclear(&i, free);
	free_world(w);
	free_comps(comps);
}

MU_TEST(test_shade_hit_is_given_an_intersection_in_shadow)
{
	t_tuple		p = point(0, 0, -10);
	t_tuple		c = color(1, 1, 1);
	t_world		*w = create_world();
	w->light = point_light(p, c);
	w->head->object = create_object('s');

	t_object	*o2 = create_object('s');
	free_matrix(o2->transform);
	o2->transform = translation(0, 0, 10);

	t_node *node = ft_calloc(1, sizeof(t_node));
	node->object = o2;
	ft_lstadd_back(&w->head, ft_lstnew(node));
	t_tuple		r_origin = point(0, 0, 5);
	t_tuple		r_direction = vector(0, 0, 1);
	t_ray		*r = create_ray(r_origin, r_direction);
	t_node		*i = new_intersection(4, w->head->next->object);
	t_comps		*comps = prepare_computations(i, r);

	t_tuple		c_shade_hit = shade_hit(w, comps);
	t_tuple		expected = color(0.1, 0.1, 0.1);

	mu_check(compare_tuples(expected, c_shade_hit));

	free(expected);
	free(c_shade_hit);
	free_ray(r);
	ft_lstclear(&i, free);
	free_world(w);
	free_comps(comps);
}

MU_TEST(test_the_hit_should_offset_the_point)
{
	t_object *o = create_object('s');
	free_matrix(o->transform);
	o->transform = translation(0, 0, 1);

	t_tuple		r_origin = point(0, 0, -5);
	t_tuple		r_direction = vector(0, 0, 1);
	t_ray		*r = create_ray(r_origin, r_direction);
	t_node		*i = new_intersection(5, o);
	t_comps		*comps = prepare_computations(i, r);

	mu_check(comps->over_point[2] < -EPSILON / 2);
	mu_check(comps->point[2] > comps->over_point[2]);

	free_ray(r);
	free_object(o);
	ft_lstclear(&i, free);
	free_comps(comps);
}

MU_TEST_SUITE(test_prepare_computations)
{
	MU_RUN_TEST(test_precomputing_the_state_of_an_intersection);
	MU_RUN_TEST(test_the_hit_when_an_intersection_occurs_on_the_outside);
	MU_RUN_TEST(test_the_hit_when_an_intersection_occurs_on_the_inside);
	MU_RUN_TEST(test_shading_an_intersection);
	MU_RUN_TEST(test_shading_an_intersection_from_the_inside);
	MU_RUN_TEST(test_shade_hit_is_given_an_intersection_in_shadow);
	MU_RUN_TEST(test_the_hit_should_offset_the_point);
}
