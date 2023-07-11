// #include <minirt.h>
// #include <minunit.h>

// MU_TEST(test_hit_intersection_sphere_all_positive_t)
// {
// 	t_object *object;
// 	object = ft_calloc(1, sizeof(t_object));
// 	object->sphere = create_sphere();
// 	t_node *i1 = new_intersection(1, object);
// 	t_node *i2 = new_intersection(2, object);
// 	t_intersect *xs = NULL;
// 	xs = add_intersection_to_list(xs, i1);
// 	xs = add_intersection_to_list(xs, i2);

// 	t_node *i = hit(xs);
// 	mu_assert(i->t == 1, "hit->t != 1");

// 	free_matrix(object->sphere->transform);
// 	free(object->sphere->material->color);
// 	free (object->sphere->material);
// 	free(object->sphere->center);
// 	free(object->sphere);
// 	free(object);
// 	free(i1);
// 	free(i2);
// 	free_list(xs);
// }

// MU_TEST(test_hit_intersection_sphere_has_negative_t)
// {
// 	t_object *object;
// 	object = ft_calloc(1, sizeof(t_object));
// 	object->sphere = create_sphere();
// 	t_node *i1 = new_intersection(-1, object);
// 	t_node *i2 = new_intersection(1, object);
// 	t_intersect *xs = NULL;
// 	xs = add_intersection_to_list(xs, i1);
// 	xs = add_intersection_to_list(xs, i2);

// 	t_node *i = hit(xs);
// 	mu_assert(i->t == 1, "hit->t != 1");

// 	free_matrix(object->sphere->transform);
// 	free(object->sphere->material->color);
// 	free (object->sphere->material);
// 	free(object->sphere->center);
// 	free(object->sphere);
// 	free(object);

// 	free(i1);
// 	free(i2);
// 	free_list(xs);
// }

// MU_TEST(test_hit_intersection_sphere_all_negative_t)
// {
// 	t_object *object;
// 	object = ft_calloc(1, sizeof(t_object));
// 	object->sphere = create_sphere();
// 	t_node *i1 = new_intersection(-2, object);
// 	t_node *i2 = new_intersection(-1, object);
// 	t_intersect *xs = NULL;
// 	xs = add_intersection_to_list(xs, i1);
// 	xs = add_intersection_to_list(xs, i2);

// 	t_node *i = hit(xs);
// 	mu_assert(i == NULL, "hit != NULL");

// 	free_matrix(object->sphere->transform);
// 	free(object->sphere->material->color);
// 	free (object->sphere->material);
// 	free(object->sphere->center);
// 	free(object->sphere);
// 	free(object);

// 	free(i1);
// 	free(i2);
// 	free_list(xs);
// }

// MU_TEST(test_hit_intersection_is_always_lowest_nonnegative_t)
// {
// 	t_object *object;
// 	object = ft_calloc(1, sizeof(t_object));
// 	object->sphere = create_sphere();
// 	t_node *i1 = new_intersection(5,object);
// 	t_node *i2 = new_intersection(7,object);
// 	t_node *i3 = new_intersection(-3,object);
// 	t_node *i4 = new_intersection(2,object);
// 	t_intersect *xs = NULL;
// 	xs = add_intersection_to_list(xs, i1);
// 	xs = add_intersection_to_list(xs, i2);
// 	xs = add_intersection_to_list(xs, i3);
// 	xs = add_intersection_to_list(xs, i4);

// 	t_node *i = hit(xs);
// 	mu_assert(i->t == 2, "hit->t != 2");

// 	free_matrix(object->sphere->transform);
// 	free(object->sphere->material->color);
// 	free (object->sphere->material);
// 	free(object->sphere->center);
// 	free(object->sphere);
// 	free(object);

// 	free(i1);
// 	free(i2);
// 	free(i3);
// 	free(i4);

// 	free_list(xs);
// }

// MU_TEST_SUITE(test_hit_intersection)
// {
// 	MU_RUN_TEST(test_hit_intersection_sphere_all_positive_t);
// 	MU_RUN_TEST(test_hit_intersection_sphere_has_negative_t);
// 	MU_RUN_TEST(test_hit_intersection_sphere_all_negative_t);
// 	MU_RUN_TEST(test_hit_intersection_is_always_lowest_nonnegative_t);
// }
