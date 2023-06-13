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
#include "matrix/inverting_matrices/determinants_test.c"
#include "matrix/inverting_matrices/spotting_submatrices_test.c"
#include "matrix/inverting_matrices/calculate_minor_test.c"
#include "matrix/inverting_matrices/calculate_cofactor_test.c"
#include "matrix/inverting_matrices/matrix_invertion_test.c"
#include "transformations/translation_test.c"
#include "transformations/scaling_test.c"
#include "transformations/rotation_test.c"
#include "transformations/shearing_test.c"

int	copy_size;

float	**copy_matrix(float a[copy_size][copy_size])
{
	float	**m = matrix(copy_size);
	for(int i = 0; i < copy_size; i++)
		for (int j = 0; j < copy_size; j++)
			m[i][j] = a[i][j];
	return (m);
}

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
	MU_RUN_SUITE(test_matrix_determinant);
	MU_RUN_SUITE(test_spotting_submatrices);
	MU_RUN_SUITE(test_calculate_minor);
	MU_RUN_SUITE(test_calculate_cofactor);
	MU_RUN_SUITE(test_matrix_invertion);
	MU_RUN_SUITE(test_translation_matrix);
	MU_RUN_SUITE(test_scaling_by_multiplication);
	MU_RUN_SUITE(test_rotation);
	MU_RUN_SUITE(shearing_test);

	MU_REPORT();
	return MU_EXIT_CODE;
}
