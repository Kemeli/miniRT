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
	t_comps	*comps = prepare_computations(i, r);

	mu_check(((t_node *)i->content)->t == comps->t);
	mu_check(compare_pointers(((t_node *)i->content)->object, comps->object));
	mu_check(compare_tuples(p_check, comps->point));
	mu_check(compare_tuples(v_check, comps->eye));
	mu_check(compare_tuples(v_check, comps->normal));

	free_comps(comps);
	free(p_check);
	free(v_check);
	ft_lstclear(&i, free);
	free_ray(r);
}

MU_TEST(test_the_hit__when_an_intersection_occurs_on_the_outside)
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
	t_comps	*comps = prepare_computations(i, r);

	mu_check(comps->inside == FALSE);

	free_comps(comps);
	free(p_check);
	free(v_check);
	ft_lstclear(&i, free);
	free_ray(r);
}

MU_TEST_SUITE(test_prepare_computations)
{
	MU_RUN_TEST(test_precomputing_the_state_of_an_intersection);
	MU_RUN_TEST(test_the_hit__when_an_intersection_occurs_on_the_outside);
}
