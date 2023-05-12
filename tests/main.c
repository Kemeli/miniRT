#include <minunit.h>
#include <minirt.h>
#include "tuples/tuple_test.c"
#include "tuples/operations/subtract_test.c"

int	main()
{
	MU_RUN_SUITE(test_tuple_identifier);
	MU_RUN_SUITE(test_tuples_subtract);
	MU_REPORT();
	return MU_EXIT_CODE;
}
