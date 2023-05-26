#include <minunit.h>
#include <minirt.h>
#include "tuples/tuple_test.c"
#include "tuples/operations/addition_test.c"
#include "tuples/operations/subtract_test.c"
#include "tuples/operations/negative_test.c"
#include "tuples/operations/multiply_divide_test.c"
#include "tuples/operations/magnitude_test.c"
#include "tuples/operations/normalization_test.c"
#include "tuples/operations/cross_product_test.c"
#include "tuples/operations/dot_product_test.c"
#include "matrix/matrix.c"
#include "tuples/colors/color_test.c"
#include "tuples/colors/multiply_colors_test.c"
#include "matrix/operations/comparing_matrix_test.c"
#include "matrix/operations/multiply_matrix_test.c"
#include "matrix/operations/transposing_matrix_test.c"

int	main()
{
	MU_RUN_SUITE(test_tuple_identifier);
	MU_RUN_SUITE(check_sum);
	MU_RUN_SUITE(test_tuples_subtract);
	MU_RUN_SUITE(test_negating_tuples);
	MU_RUN_SUITE(test_multiply_divide);
	MU_RUN_SUITE(test_magnitude);
	MU_RUN_SUITE(test_tuples_normalization);
	MU_RUN_SUITE(test_cross_product);
	MU_RUN_SUITE(test_dot_product);
	MU_RUN_SUITE(test_color_creation);
	MU_RUN_TEST(test_matrix_4x4_are_equal);
	MU_RUN_SUITE(test_cross_product);
	MU_RUN_SUITE(test_color_mutltiplication);
	MU_RUN_SUITE(test_creating_matrix);
	MU_RUN_SUITE(test_comparing_matrices);
	MU_RUN_SUITE(test_multiply_matrix);
	MU_RUN_SUITE(test_transposing_matrix);
	MU_REPORT();
	return MU_EXIT_CODE;
}
