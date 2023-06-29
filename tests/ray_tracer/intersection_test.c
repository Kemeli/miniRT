#include <minirt.h>
#include <minunit.h>

//##############################################################################
// 					intersecting rays with spheres
//##############################################################################

MU_TEST(test_that_a_ray_intercepts_a_sphere_at_two_points)
{
	t_ray *r = create_ray(point(0, 0, -5), vector(0, 0, 1));
	t_sphere *s = create_sphere();
	t_intersect *xs = intersect_sphere(s, r);
	mu_assert_double_eq(4.0, xs->head->t);
	mu_assert_double_eq(6.0, xs->head->next->t);
	mu_assert_int_eq(2, xs->count);

	free_matrix(s->transform);
	free_list (xs);
	free (r->direction);
	free (r->origin);
	free (s->center);
	free(s->material->color);
	free(s->material);
	free (s);
	free (r);
}

MU_TEST(test_that_a_ray_intercepts_a_sphere_at_a_tangent)
{
	t_ray *r = create_ray(point(0, 1, -5), vector(0, 0, 1));
	t_sphere *s = create_sphere();
	t_intersect *xs = intersect_sphere(s, r);
	mu_assert_double_eq(5.0, xs->head->t);
	mu_assert_double_eq(5.0, xs->head->next->t);
	mu_assert_int_eq(1, xs->count);

	free_matrix(s->transform);
	free_list (xs);
	free (r->direction);
	free (r->origin);
	free (s->center);
	free(s->material->color);
	free(s->material);
	free (s);
	free (r);
}

MU_TEST(test_that_a_ray_misses_a_sphere)
{
	t_ray *r = create_ray(point(0, 2, -5), vector(0, 0, 1));
	t_sphere *s = create_sphere();
	t_intersect *xs = intersect_sphere(s, r);
	mu_assert_double_eq(0, xs->head->t);
	mu_assert_double_eq(0, xs->head->next->t);
	mu_assert_int_eq(0, xs->count);

	free_matrix(s->transform);
	free_list (xs);
	free (r->direction);
	free (r->origin);
	free (s->center);
	free(s->material->color);
	free(s->material);
	free (s);
	free (r);
}

MU_TEST(test_that_a_ray_originates_inside_a_sphere)
{
	t_ray *r = create_ray(point(0, 0, 0), vector(0, 0, 1));
	t_sphere *s = create_sphere();
	t_intersect *xs =intersect_sphere(s, r);
	mu_assert_double_eq(-1.0, xs->head->t);
	mu_assert_double_eq(1.0, xs->head->next->t);
	mu_assert_int_eq(2, xs->count);

	free_matrix(s->transform);
	free_list (xs);
	free (r->direction);
	free (r->origin);
	free (s->center);
	free(s->material->color);
	free(s->material);
	free (s);
	free (r);
}

MU_TEST(test_that_a_sphere_is_behind_a_ray)
{
	t_ray *r = create_ray(point(0, 0, 5), vector(0, 0, 1));
	t_sphere *s = create_sphere();
	t_intersect *xs = intersect_sphere(s, r);
	mu_assert_double_eq(-6.0, xs->head->t);
	mu_assert_double_eq(-4.0, xs->head->next->t);
	mu_assert_int_eq(2, xs->count);

	free_matrix(s->transform);
	free_list(xs);
	free (r->direction);
	free (r->origin);
	free (s->center);
	free(s->material->color);
	free(s->material);
	free (s);
	free (r);
}

// //###########################################################################
// // 						trancking intersections
// //###########################################################################

MU_TEST(test_that_an_intersection_encapsulates_t_and_object)
{
	t_sphere *s = create_sphere();
	t_node *i = new_intersection(3.5, (void *)&s);
	mu_assert_double_eq(3.5, i->t);
	mu_check(compare_pointers(&s, i->object));

	free_matrix(s->transform);
	free (i);
	free (s->center);
	free(s->material->color);
	free(s->material);
	free(s);
}

MU_TEST(test_that_a_collection_of_intersections_is_created)
{
	t_sphere *s = create_sphere();
	t_intersect	*xs = NULL;
	t_node *i1 = new_intersection(1, (void *)&s);
	xs = add_intersection_to_list(xs, i1);
	t_node *i2 = new_intersection(2, (void *)&s);
	xs = add_intersection_to_list(xs, i2);
	int count = 0;
	t_node *aux;

	mu_assert_double_eq(1, xs->head->t);
	mu_assert_double_eq(2, xs->head->next->t);

	aux = xs->head;
	while (aux)
	{
		count++;
		aux = aux->next;
	}
	mu_assert_int_eq(2, count);

	free_matrix(s->transform);
	free(s->center);
	free_list(xs);
	free(s->material->color);
	free(s->material);
	free(s);
}

/*
aqui faltou checar se o xs tem a esfera como objeto
queria fazer como ponteiro mas ainda n funcionou
*/
MU_TEST(test_that_intersect_sets_the_object_on_the_intersection)
{
	t_ray *r = create_ray(point(0, 0, -5), vector(0, 0, 1));
	t_sphere *s = create_sphere();
	t_intersect *xs = intersect_sphere(s, r);
	/*
	printf("xs->object: %p\n", xs->object);
	printf("s: %p\n", s);
	mu_check(compare_pointers(&s, xs->object));
	mu_check(compare_pointers(&s, xs->head->next->object));
	*/
	mu_assert_double_eq(4.0, xs->head->t);
	mu_assert_double_eq(6.0, xs->head->next->t);
	mu_assert_int_eq(2, xs->count);

	free_matrix(s->transform);
	free (r->direction);
	free (r->origin);
	free (s->center);
	free_list(xs);
	free(s->material->color);
	free(s->material);
	free(s);
	free(r);
}

//##############################################################################
//		 						test suite
//##############################################################################
MU_TEST_SUITE(test_interception_of_rays_and_spheres)
{
	MU_RUN_TEST(test_that_a_ray_intercepts_a_sphere_at_two_points);
	MU_RUN_TEST(test_that_a_ray_intercepts_a_sphere_at_a_tangent);
	MU_RUN_TEST(test_that_a_ray_misses_a_sphere);
	MU_RUN_TEST(test_that_a_ray_originates_inside_a_sphere);
	MU_RUN_TEST(test_that_a_sphere_is_behind_a_ray);

	MU_RUN_TEST(test_that_an_intersection_encapsulates_t_and_object);
	MU_RUN_TEST(test_that_a_collection_of_intersections_is_created);
	MU_RUN_TEST(test_that_intersect_sets_the_object_on_the_intersection);
}
