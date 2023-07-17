#include <minirt.h>
#include <minunit.h>

MU_TEST(test_precomputing_the_state_of_an_intersection)
{
	t_sphere	*s = create_sphere();
	t_object	*obj;
	t_tuple		p = point(0, 0, -5);
	t_tuple		p_check = point(0, 0, -1);
	t_tuple		v = vector(0, 0, 1);
	t_tuple		v_check = vector(0, 0, -1);
	t_ray		*r = create_ray(p, v);

	obj = ft_calloc(1, sizeof(t_object));
	obj->sphere = s;
	t_list	*i = new_intersection(4, obj);
	t_comps	*comps = prepare_computations(((t_node *)i->content), r);

	mu_check(((t_node *)i->content)->t == comps->t);
	mu_check(compare_pointers(((t_node *)i->content)->object, comps->object));
	mu_check(compare_tuples(p_check, comps->point));
	mu_check(compare_tuples(v_check, comps->eye));
	mu_check(compare_tuples(v_check, comps->normal));

	free_object(obj);
	free_comps(comps);
	free(p_check);
	free(v_check);
	ft_lstclear(&i, free);
	free_ray(r);
}

MU_TEST(test_the_hit_when_an_intersection_occurs_on_the_outside)
{
	t_sphere	*s = create_sphere();
	t_object	*obj;
	t_tuple		p = point(0, 0, -5);
	t_tuple		v = vector(0, 0, 1);
	t_ray		*r = create_ray(p, v);
	t_tuple		p_check = point(0, 0, -1);
	t_tuple		v_check = vector(0, 0, -1);

	obj = ft_calloc(1, sizeof(t_object));
	obj->sphere = s;
	t_list	*i = new_intersection(4, obj);
	t_comps	*comps = prepare_computations(((t_node *)i->content), r);

	mu_check(comps->inside == FALSE);

	free_object(obj);
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

	t_object	*obj = ft_calloc(1, sizeof(t_object));
	obj->sphere = create_sphere();
	t_list		*i = new_intersection(1, obj);
	t_comps		*comps = prepare_computations(((t_node *)i->content), r);

	t_tuple		p_expected = point(0, 0, 1);
	t_tuple		v_expected = vector(0, 0, -1);

	mu_check(comps->inside == TRUE);
	mu_check(compare_tuples(p_expected, comps->point));
	mu_check(compare_tuples(v_expected, comps->eye));
	mu_check(compare_tuples(v_expected, comps->normal));

	free_object(obj);
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

	t_list		*i = new_intersection(4, ((t_node *)w->head->content)->object);

	t_comps		*comps = prepare_computations(((t_node *)i->content), r);
	t_tuple		c = shade_hit(w, comps);
	t_tuple		expected = color(0.38066, 0.47583, 0.2855);

	mu_check(compare_tuples(expected, c));

	free(expected);
	free(c);
	free_ray(r);
	ft_lstclear(&i, free);
	free_world(w);
	free_comps(comps);
}

MU_TEST_SUITE(test_shading_an_intersection_from_the_inside)
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
	t_list		*i = new_intersection(0.5, ((t_node *)w->head->next->content)->object);
	t_comps		*comps = prepare_computations(((t_node *)i->content), r);

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

MU_TEST_SUITE(test_prepare_computations)
{
	MU_RUN_TEST(test_precomputing_the_state_of_an_intersection);
	MU_RUN_TEST(test_the_hit_when_an_intersection_occurs_on_the_outside);
	MU_RUN_TEST(test_the_hit_when_an_intersection_occurs_on_the_inside);
	MU_RUN_TEST(test_shading_an_intersection);
	MU_RUN_TEST(test_shading_an_intersection_from_the_inside);
}
