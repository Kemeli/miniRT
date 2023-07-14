#include <minirt.h>
#include <minunit.h>

//##############################################################################
// 					intersecting rays with spheres
//##############################################################################


MU_TEST(test_that_a_ray_intercepts_a_sphere_at_two_points)
{
	t_ray *r = create_ray(point(0, 0, -5), vector(0, 0, 1));
	t_object *object = ft_calloc(1, sizeof(t_object));
	object->sphere = create_sphere();
	t_intersect *xs = intersect_sphere(object, r);
	mu_assert_double_eq(4.0, ((t_node*)xs->head->content)->t);
	mu_assert_double_eq(6.0, ((t_node*)xs->head->next->content)->t);
	mu_assert_int_eq(2, xs->count);

	free_intersections (xs);
	free (r->direction);
	free (r->origin);
	free (r);

	free_matrix(object->sphere->transform);
	free(object->sphere->material->color);
	free (object->sphere->material);
	free(object->sphere->center);
	free(object->sphere);
	free(object);
}

MU_TEST(test_that_a_ray_intercepts_a_sphere_at_a_tangent)
{
	t_ray *r = create_ray(point(0, 1, -5), vector(0, 0, 1));
	t_object *object = ft_calloc(1, sizeof(t_object));
	object->sphere = create_sphere();
	t_intersect *xs = intersect_sphere(object, r);
	mu_assert_double_eq(5.0, ((t_node*)xs->head->content)->t);
	mu_assert_double_eq(5.0, ((t_node*)xs->head->next->content)->t);
	mu_assert_int_eq(1, xs->count);

	free_intersections (xs);
	free (r->direction);
	free (r->origin);
	free (r);

	free_matrix(object->sphere->transform);
	free(object->sphere->material->color);
	free (object->sphere->material);
	free(object->sphere->center);
	free(object->sphere);
	free(object);
}

MU_TEST(test_that_a_ray_misses_a_sphere)
{
	t_ray *r = create_ray(point(0, 2, -5), vector(0, 0, 1));
	t_object *object = ft_calloc(1, sizeof(t_object));
	object->sphere = create_sphere();
	t_intersect *xs = intersect_sphere(object, r);
	mu_assert_double_eq(0, ((t_node*)xs->head->content)->t);
	mu_assert_double_eq(0, ((t_node*)xs->head->next->content)->t);
	mu_assert_int_eq(0, xs->count);

	free_intersections (xs);
	free (r->direction);
	free (r->origin);
	free (r);

	free_matrix(object->sphere->transform);
	free(object->sphere->material->color);
	free (object->sphere->material);
	free(object->sphere->center);
	free(object->sphere);
	free(object);
}

MU_TEST(test_that_a_ray_originates_inside_a_sphere)
{
	t_ray *r = create_ray(point(0, 0, 0), vector(0, 0, 1));
	t_object *object = ft_calloc(1, sizeof(t_object));
	object->sphere = create_sphere();
	t_intersect *xs = intersect_sphere(object, r);
	mu_assert_double_eq(-1.0, ((t_node*)xs->head->content)->t);
	mu_assert_double_eq(1.0, ((t_node*)xs->head->next->content)->t);
	mu_assert_int_eq(2, xs->count);

	free_intersections (xs);
	free (r->direction);
	free (r->origin);
	free (r);

	free_matrix(object->sphere->transform);
	free(object->sphere->material->color);
	free (object->sphere->material);
	free(object->sphere->center);
	free(object->sphere);
	free(object);
}

MU_TEST(test_that_a_sphere_is_behind_a_ray)
{
	t_ray *r = create_ray(point(0, 0, 5), vector(0, 0, 1));
	t_object *object = ft_calloc(1, sizeof(t_object));
	object->sphere = create_sphere();
	t_intersect *xs = intersect_sphere(object, r);
	mu_assert_double_eq(-6.0, ((t_node*)xs->head->content)->t);
	mu_assert_double_eq(-4.0, ((t_node*)xs->head->next->content)->t);
	mu_assert_int_eq(2, xs->count);

	free_intersections(xs);
	free (r->direction);
	free (r->origin);
	free (r);

	free_matrix(object->sphere->transform);
	free(object->sphere->material->color);
	free (object->sphere->material);
	free(object->sphere->center);
	free(object->sphere);
	free(object);
}

// // //###########################################################################
// // // 						trancking intersections
// // //###########################################################################

MU_TEST(test_that_an_intersection_encapsulates_t_and_object)
{
	t_object *object;
	object = ft_calloc(1, sizeof(t_object));
	object->sphere = create_sphere();
	t_list *i = new_intersection(3.5, object);
	mu_assert_double_eq(3.5, ((t_node*)i->content)->t);
	mu_check(compare_pointers(&object->sphere, ((t_node*)i->content)->object));

	free(i->content);
	free (i);

	free_matrix(object->sphere->transform);
	free(object->sphere->material->color);
	free (object->sphere->material);
	free(object->sphere->center);
	free(object->sphere);
	free(object);
}

MU_TEST(test_that_a_collection_of_intersections_is_created)
{
	t_object *object;
	object = ft_calloc(1, sizeof(t_object));
	object->sphere = create_sphere();

	t_list *i1 = new_intersection(1, object);
	t_list *i2 = new_intersection(2, object);
	t_intersect	*xs = ft_calloc(1, sizeof(t_intersect));
	ft_lstadd_back(&i1, i2);
	xs->head = i1;

	mu_assert_double_eq(1, ((t_node*)xs->head->content)->t);
	mu_assert_double_eq(2, ((t_node*)xs->head->next->content)->t);

	int count = 0;
	t_list *aux;
	aux = xs->head;
	while (aux)
	{
		count++;
		aux = aux->next;
	}
	mu_assert_int_eq(2, count);

	free_intersections(xs);

	free_matrix(object->sphere->transform);
	free(object->sphere->material->color);
	free (object->sphere->material);
	free(object->sphere->center);
	free(object->sphere);
	free(object);
}

MU_TEST(test_that_intersect_sets_the_object_on_the_intersection)
{
	t_ray *r = create_ray(point(0, 0, -5), vector(0, 0, 1));
	t_object *object = ft_calloc(1, sizeof(t_object));
	object->sphere = create_sphere();
	t_intersect *xs = intersect_sphere(object, r);

	mu_check(compare_pointers(&object->sphere, ((t_node*)xs->head->content)->object));
	mu_check(compare_pointers(&object->sphere, ((t_node*)xs->head->next->content)->object));
	mu_assert_double_eq(4.0, ((t_node*)xs->head->content)->t);
	mu_assert_double_eq(6.0, ((t_node*)xs->head->next->content)->t);
	mu_assert_int_eq(2, xs->count);

	free (r->direction);
	free (r->origin);
	free_intersections(xs);
	free(r);

	free_matrix(object->sphere->transform);
	free(object->sphere->material->color);
	free (object->sphere->material);
	free(object->sphere->center);
	free(object->sphere);
	free(object);
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
