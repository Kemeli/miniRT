#include <minunit.h>
#include <minirt.h>

MU_TEST(check_sum_between_a_point_and_a_vector)
{
    t_tuple point_to_sum;
    t_tuple vector_to_sum;
    t_tuple result;
    t_tuple expected;

    point_to_sum = point(3, -2, 5);
    vector_to_sum = vector(-2, 3, 1);
    expected = tuple (1, 1, 6, 1);
    result = addition(point_to_sum, vector_to_sum);

    mu_check(compare_tuples(result, expected));
}

MU_TEST(check_sum_between_a_point_and_a_point)
{
    t_tuple point1_to_sum;
    t_tuple point2_to_sum;
    t_tuple result;
    t_tuple expected;

    point1_to_sum = point(3, -2, 5);
    point2_to_sum = point(-2, 3, 1);
    expected = tuple (1, 1, 6, 2);
    result = addition(point1_to_sum, point2_to_sum);

    mu_check(compare_tuples(result, expected));
}

MU_TEST(check_sum_between_a_vector_and_a_vector)
{
    t_tuple vector1_to_sum;
    t_tuple vector2_to_sum;
    t_tuple result;
    t_tuple expected;

    vector1_to_sum = vector(2, -2, 3);
    vector2_to_sum = vector(-1, 2, 3);
    expected = tuple (1, 0, 6, 0);
    result = addition(vector1_to_sum, vector2_to_sum);

    mu_check(compare_tuples(result, expected));
}

MU_TEST_SUITE(check_sum)
{
	MU_RUN_TEST(check_sum_between_a_point_and_a_vector);
	MU_RUN_TEST(check_sum_between_a_point_and_a_point);
	MU_RUN_TEST(check_sum_between_a_vector_and_a_vector);
}
