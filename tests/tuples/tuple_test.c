#include <minunit.h>
#include <minirt.h>

MU_TEST(test_point_identifier)
{
	t_tuple	a = tuple(4.3, -4.2, 3.1, 1.0);

	mu_assert_double_eq(a[0], 4.3);
	mu_assert_double_eq(a[1], -4.2);
	mu_assert_double_eq(a[2], 3.1);
	mu_assert(a[3] == 1.0, "tuple 'a' should be a point");
	free(a);
}

MU_TEST(test_vector_identifier)
{
	t_tuple	a = tuple(4.3, -4.2, 3.1, 0);

	mu_assert_double_eq(a[0], 4.3);
	mu_assert_double_eq(a[1], -4.2);
	mu_assert_double_eq(a[2], 3.1);
	mu_assert(a[3] == 0, "tuple 'a' should be a vector");
	free(a);
}

MU_TEST(test_vector_create)
{
	t_tuple a = vector(4.3, -4.2, 3.1);

	mu_assert(a[3] == 0, "function vector should create a vector");
	free(a);
}

MU_TEST(test_point_create)
{
	t_tuple a = point(4.3, -4.2, 3.1);

	mu_assert(a[3] == 1, "function point should create a point");
	free(a);
}

MU_TEST(test_tuples_comparing)
{
	t_tuple a = point(1.0, 10.0, -1.5);
	t_tuple b = point(1.0, 10.0, -1.5);
	mu_check(compare_tuples(a, b));
	free(a);
	free(b);

 	a = vector(2.0, 10.0, -1.5);
	b = vector(2.0, 10.0, -1.5);
	mu_check(compare_tuples(a, b));
	free(a);
	free(b);

	a = point(5.0, 15.2, 3.1);
	b = vector(5.0, 15.2, 3.1);
	mu_check(compare_tuples(a, b) == 0);
	free(a);
	free(b);

	a = point(5.0, 15.2, 3);
	b = point(5.0, 15.2, 3.1);
	mu_check(compare_tuples(a, b) == 0);
	free(a);
	free(b);

	a = vector(5.0, 15.2, 3);
	b = vector(5.0, 15.2, 3.0001);
	mu_check(compare_tuples(a, b) == 0);
	free(a);
	free(b);
}

MU_TEST_SUITE(test_tuple_identifier)
{
	MU_RUN_TEST(test_point_identifier);
	MU_RUN_TEST(test_vector_identifier);
	MU_RUN_TEST(test_vector_create);
	MU_RUN_TEST(test_point_create);
	MU_RUN_TEST(test_tuples_comparing);
}
