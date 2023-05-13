#include <minunit.h>
#include <minirt.h>

MU_TEST(check_sum_between_a_point_and_a_vector)
{
    t_tuple point_to_sum;
    t_tuple vector_to_sum;
    t_tuple result;
    t_tuple expected;

    float a_x = 3;
    float a_y = -2;
    float a_z = 5;
    
    float b_x = -2;
    float b_y = 3;
    float b_z = 1;

    point_to_sum = point(a_x, a_y, a_z);
    vector_to_sum = vector(b_x, b_y, b_z);
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


    float a_x = 3;
    float a_y = -2;
    float a_z = 5;
    
    float b_x = -2;
    float b_y = 3;
    float b_z = 1;

    point1_to_sum = point(a_x, a_y, a_z);
    point2_to_sum = point(b_x, b_y, b_z);
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

    float a_x = 2;
    float a_y = -2;
    float a_z = 3;
    
    float b_x = -1;
    float b_y = 2;
    float b_z = 3;

    vector1_to_sum = vector(a_x, a_y, a_z);
    vector2_to_sum = vector(b_x, b_y, b_z);
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
