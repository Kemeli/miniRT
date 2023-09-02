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

//##############################################################################
//					ray_strikes_a_cylinder
//##############################################################################

MU_TEST(test_a_ray_strikes_a_cylinder)
{
	t_object *o = create_object('c');

	t_tuple orgin = point(1, 0, -5);
	t_tuple direction = vector(0, 0, 1);
	t_tuple norm_direction = normalize(direction);
	t_ray *r = create_ray(orgin, norm_direction);

	t_intersect *xs = intersect(&o, r);
	mu_check(xs->count == 2);
	mu_check(xs->head->t == 5);
	mu_check(xs->head->next->t == 5);

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
	mu_check(xs->head->t == 4);
	mu_check(xs->head->next->t == 6);

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

	mu_check(compare_doubles(xs->head->t, 6.8080)); // 6.80798
	mu_check(compare_doubles(xs->head->next->t, 7.0887));

	free(direction);
	free_intersections(xs);
	free_ray(r);
	free_object(o);
}

//##############################################################################
//					normal_vector_on_a_cylinder
//##############################################################################

MU_TEST(test_the_normal_vector_on_a_cylinder)
{
	t_object *o = create_object('c');
	t_tuple p = point(1, 0, 0);

	t_tuple normal = local_normal_at(o, p);
	t_tuple expected = vector(1, 0, 0);
	mu_check(compare_tuples(normal, expected));

	free_object(o);
	free(p);
	free(normal);
	free(expected);
}

MU_TEST(test_the_normal_vector_on_a_cylinder2)
{
	t_object *o = create_object('c');
	t_tuple p = point(0, 5, -1);

	t_tuple normal = local_normal_at(o, p);
	t_tuple expected = vector(0, 0, -1);
	mu_check(compare_tuples(normal, expected));

	free_object(o);
	free(p);
	free(normal);
	free(expected);
}

MU_TEST(test_the_normal_vector_on_a_cylinder3)
{
	t_object *o = create_object('c');
	t_tuple p = point(0, -2, 1);

	t_tuple normal = local_normal_at(o, p);
	t_tuple expected = vector(0, 0, 1);
	mu_check(compare_tuples(normal, expected));

	free_object(o);
	free(p);
	free(normal);
	free(expected);
}

MU_TEST(test_the_normal_vector_on_a_cylinder4)
{
	t_object *o = create_object('c');
	t_tuple p = point(-1, 1, 0);

	t_tuple normal = local_normal_at(o, p);
	t_tuple expected = vector(-1, 0, 0);
	mu_check(compare_tuples(normal, expected));

	free_object(o);
	free(p);
	free(normal);
	free(expected);
}

//##############################################################################
//					default_minimum_and_maximum_for_a_cylinder
//##############################################################################

MU_TEST(test_the_default_minimum_and_maximum_for_a_cylinder)
{
	t_object *o = create_object('c');

	mu_check(o->cylinder->minimum == -INFINITY);
	mu_check(o->cylinder->maximum == INFINITY);

	free_object(o);
}

//##############################################################################
//					Truncated Cylinders
//##############################################################################

MU_TEST(test_intersecting_a_constrained_cylinder1)
{
	t_object *o = create_object('c');

	o->cylinder->minimum = 1;
	o->cylinder->maximum = 2;

	t_tuple direction = vector(0.1, 1, 0);
	t_tuple norm_direction = normalize(direction);
	t_tuple origin = point(0, 1.5, 0);
	t_ray *r = create_ray(origin, norm_direction);

	t_intersect *xs = intersect(&o, r);

	mu_check(xs->count == 0);

	free(direction);
	free_ray(r);
	free_intersections(xs);
	free_object(o);
}

MU_TEST(test_intersecting_a_constrained_cylinder2)
{
	t_object *o = create_object('c');

	o->cylinder->minimum = 1;
	o->cylinder->maximum = 2;

	t_tuple direction = vector(0, 0, 1);
	t_tuple norm_direction = normalize(direction);
	t_tuple origin = point(0, 3, -5);
	t_ray *r = create_ray(origin, norm_direction);

	t_intersect *xs = intersect(&o, r);

	mu_check(xs->count == 0);

	free(direction);
	free_ray(r);
	free_intersections(xs);
	free_object(o);
}
MU_TEST(test_intersecting_a_constrained_cylinder3)
{
	t_object *o = create_object('c');

	o->cylinder->minimum = 1;
	o->cylinder->maximum = 2;

	t_tuple direction = vector(0, 0, 1);
	t_tuple norm_direction = normalize(direction);
	t_tuple origin = point(0, 0, -5);
	t_ray *r = create_ray(origin, norm_direction);

	t_intersect *xs = intersect(&o, r);

	mu_check(xs->count == 0);

	free(direction);
	free_ray(r);
	free_intersections(xs);
	free_object(o);
}
MU_TEST(test_intersecting_a_constrained_cylinder4)
{
	t_object *o = create_object('c');

	o->cylinder->minimum = 1;
	o->cylinder->maximum = 2;

	t_tuple direction = vector(0, 0, 1);
	t_tuple norm_direction = normalize(direction);
	t_tuple origin = point(0, 2, -5);
	t_ray *r = create_ray(origin, norm_direction);

	t_intersect *xs = intersect(&o, r);

	mu_check(xs->count == 0);

	free(direction);
	free_ray(r);
	free_intersections(xs);
	free_object(o);
}
MU_TEST(test_intersecting_a_constrained_cylinder5)
{
	t_object *o = create_object('c');

	o->cylinder->minimum = 1;
	o->cylinder->maximum = 2;

	t_tuple direction = vector(0, 0, 1);
	t_tuple norm_direction = normalize(direction);
	t_tuple origin = point(0, 1, -5);
	t_ray *r = create_ray(origin, norm_direction);

	t_intersect *xs = intersect(&o, r);

	mu_check(xs->count == 0);

	free(direction);
	free_ray(r);
	free_intersections(xs);
	free_object(o);
}
MU_TEST(test_intersecting_a_constrained_cylinder6)
{
	t_object *o = create_object('c');

	o->cylinder->minimum = 1;
	o->cylinder->maximum = 2;

	t_tuple direction = vector(0, 0, 1);
	t_tuple norm_direction = normalize(direction);
	t_tuple origin = point(0, 1.5, -2);
	t_ray *r = create_ray(origin, norm_direction);

	t_intersect *xs = intersect(&o, r);

	mu_check(xs->count == 2);

	free(direction);
	free_ray(r);
	free_intersections(xs);
	free_object(o);
}

MU_TEST(test_the_default_closed_value_for_a_cylinder)
{
	t_object *o = create_object('c');

	mu_check(o->cylinder->closed == FALSE);

	free_object(o);
}

MU_TEST(test_intersecting_the_caps_of_a_closed_cylinder1)
{
	t_object *o = create_object('c');

	o->cylinder->minimum = 1;
	o->cylinder->maximum = 2;
	o->cylinder->closed = TRUE;

	t_tuple direction = vector(0, -1, 0);
	t_tuple norm_direction = normalize(direction);
	t_tuple origin = point(0, 3, 0);
	t_ray *r = create_ray(origin, norm_direction);

	t_intersect *xs = intersect(&o, r);

	mu_check(xs->count == 2);

	free(direction);
	free_ray(r);
	free_intersections(xs);
	free_object(o);
}

MU_TEST(test_intersecting_the_caps_of_a_closed_cylinder2)
{
	t_object *o = create_object('c');

	o->cylinder->minimum = 1;
	o->cylinder->maximum = 2;
	o->cylinder->closed = TRUE;

	t_tuple direction = vector(0, -1, 2);
	t_tuple norm_direction = normalize(direction);
	t_tuple origin = point(0, 3, -2);
	t_ray *r = create_ray(origin, norm_direction);

	t_intersect *xs = intersect(&o, r);

	mu_check(xs->count == 2);

	free(direction);
	free_ray(r);
	free_intersections(xs);
	free_object(o);
}

MU_TEST(test_intersecting_the_caps_of_a_closed_cylinder3)
{
	t_object *o = create_object('c');

	o->cylinder->minimum = 1;
	o->cylinder->maximum = 2;
	o->cylinder->closed = TRUE;

	t_tuple direction = vector(0, -1, 1);
	t_tuple norm_direction = normalize(direction);
	t_tuple origin = point(0, 4, -2);
	t_ray *r = create_ray(origin, norm_direction);

	t_intersect *xs = intersect(&o, r);

	mu_check(xs->count == 2);

	free(direction);
	free_ray(r);
	free_intersections(xs);
	free_object(o);
}

MU_TEST(test_intersecting_the_caps_of_a_closed_cylinder4)
{
	t_object *o = create_object('c');

	o->cylinder->minimum = 1;
	o->cylinder->maximum = 2;
	o->cylinder->closed = TRUE;

	t_tuple direction = vector(0, 1, 2);
	t_tuple norm_direction = normalize(direction);
	t_tuple origin = point(0, 0, -2);
	t_ray *r = create_ray(origin, norm_direction);

	t_intersect *xs = intersect(&o, r);

	mu_check(xs->count == 2);

	free(direction);
	free_ray(r);
	free_intersections(xs);
	free_object(o);
}

MU_TEST(test_intersecting_the_caps_of_a_closed_cylinder5)
{
	t_object *o = create_object('c');

	o->cylinder->minimum = 1;
	o->cylinder->maximum = 2;
	o->cylinder->closed = TRUE;

	t_tuple direction = vector(0, 1, 1);
	t_tuple norm_direction = normalize(direction);
	t_tuple origin = point(0, -1, -2);
	t_ray *r = create_ray(origin, norm_direction);

	t_intersect *xs = intersect(&o, r);

	mu_check(xs->count == 2);

	free(direction);
	free_ray(r);
	free_intersections(xs);
	free_object(o);
}

MU_TEST(test_the_normal_vector_on_a_cylinders_end_caps1)
{
	t_object *o = create_object('c');

	o->cylinder->minimum = 1;
	o->cylinder->maximum = 2;
	o->cylinder->closed = TRUE;

	t_tuple p = point(0, 1, 0);
	t_tuple normal = vector(0, -1, 0);
	t_tuple n = local_normal_at(o, p);

	mu_check(compare_tuples(normal, n));

	free(p);
	free(normal);
	free(n);
	free_object(o);
}

MU_TEST(test_the_normal_vector_on_a_cylinders_end_caps2)
{
	t_object *o = create_object('c');

	o->cylinder->minimum = 1;
	o->cylinder->maximum = 2;
	o->cylinder->closed = TRUE;

	t_tuple p = point(0.5, 1, 0);
	t_tuple normal = vector(0, -1, 0);
	t_tuple n = local_normal_at(o, p);

	mu_check(compare_tuples(normal, n));

	free(p);
	free(normal);
	free(n);
	free_object(o);
}

MU_TEST(test_the_normal_vector_on_a_cylinders_end_caps3)
{
	t_object *o = create_object('c');

	o->cylinder->minimum = 1;
	o->cylinder->maximum = 2;
	o->cylinder->closed = TRUE;

	t_tuple p = point(0, 1, 0.5);
	t_tuple normal = vector(0, -1, 0);
	t_tuple n = local_normal_at(o, p);

	mu_check(compare_tuples(normal, n));

	free(p);
	free(normal);
	free(n);
	free_object(o);
}

MU_TEST(test_the_normal_vector_on_a_cylinders_end_caps4)
{
	t_object *o = create_object('c');

	o->cylinder->minimum = 1;
	o->cylinder->maximum = 2;
	o->cylinder->closed = TRUE;

	t_tuple p = point(0, 2, 0);
	t_tuple normal = vector(0, 1, 0);
	t_tuple n = local_normal_at(o, p);

	mu_check(compare_tuples(normal, n));

	free(p);
	free(normal);
	free(n);
	free_object(o);
}

MU_TEST(test_the_normal_vector_on_a_cylinders_end_caps5)
{
	t_object *o = create_object('c');

	o->cylinder->minimum = 1;
	o->cylinder->maximum = 2;
	o->cylinder->closed = TRUE;

	t_tuple p = point(0.5, 2, 0);
	t_tuple normal = vector(0, 1, 0);
	t_tuple n = local_normal_at(o, p);

	mu_check(compare_tuples(normal, n));

	free(p);
	free(normal);
	free(n);
	free_object(o);
}

MU_TEST(test_the_normal_vector_on_a_cylinders_end_caps6)
{
	t_object *o = create_object('c');

	o->cylinder->minimum = 1;
	o->cylinder->maximum = 2;
	o->cylinder->closed = TRUE;

	t_tuple p = point(0, 2, 0.5);
	t_tuple normal = vector(0, 1, 0);
	t_tuple n = local_normal_at(o, p);

	mu_check(compare_tuples(normal, n));

	free(p);
	free(normal);
	free(n);
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

	MU_RUN_TEST(test_the_normal_vector_on_a_cylinder);
	MU_RUN_TEST(test_the_normal_vector_on_a_cylinder2);
	MU_RUN_TEST(test_the_normal_vector_on_a_cylinder3);
	MU_RUN_TEST(test_the_normal_vector_on_a_cylinder4);

	MU_RUN_TEST(test_the_default_minimum_and_maximum_for_a_cylinder);

	MU_RUN_TEST(test_intersecting_a_constrained_cylinder1);
	MU_RUN_TEST(test_intersecting_a_constrained_cylinder2);
	MU_RUN_TEST(test_intersecting_a_constrained_cylinder3);
	MU_RUN_TEST(test_intersecting_a_constrained_cylinder4);
	MU_RUN_TEST(test_intersecting_a_constrained_cylinder5);
	MU_RUN_TEST(test_intersecting_a_constrained_cylinder6);

	MU_RUN_TEST(test_the_default_closed_value_for_a_cylinder);

	MU_RUN_TEST(test_intersecting_the_caps_of_a_closed_cylinder1);
	MU_RUN_TEST(test_intersecting_the_caps_of_a_closed_cylinder2);
	MU_RUN_TEST(test_intersecting_the_caps_of_a_closed_cylinder3);
	MU_RUN_TEST(test_intersecting_the_caps_of_a_closed_cylinder4);
	MU_RUN_TEST(test_intersecting_the_caps_of_a_closed_cylinder5);

	MU_RUN_TEST(test_the_normal_vector_on_a_cylinders_end_caps1);
	MU_RUN_TEST(test_the_normal_vector_on_a_cylinders_end_caps2);
	MU_RUN_TEST(test_the_normal_vector_on_a_cylinders_end_caps3);
	MU_RUN_TEST(test_the_normal_vector_on_a_cylinders_end_caps4);
	MU_RUN_TEST(test_the_normal_vector_on_a_cylinders_end_caps5);
	MU_RUN_TEST(test_the_normal_vector_on_a_cylinders_end_caps6);
}
