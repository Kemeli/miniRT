#include <minunit.h>
#include <minirt.h>
#include "tuples/tuple_test.c"
#include "tuples/operations/addition_test.c"
#include "tuples/operations/subtract_test.c"
#include "tuples/operations/negative_test.c"
#include "tuples/operations/multiply_divide_test.c"
#include "tuples/operations/magnitude_test.c"

int	main()
{
	MU_RUN_SUITE(test_tuple_identifier);
	MU_RUN_SUITE(check_sum);
	MU_RUN_SUITE(test_tuples_subtract);
	MU_RUN_SUITE(test_negating_tuples);
	MU_RUN_SUITE(test_multiply_divide);
	MU_RUN_SUITE(test_magnitude);
	MU_REPORT();
	return MU_EXIT_CODE;
}
