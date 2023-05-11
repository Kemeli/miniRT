#include <minunit.h>
#include <minirt.h>

int	main()
{
	MU_RUN_SUITE(test_tuple_identifier);
	MU_REPORT();
	return MU_EXIT_CODE;
}
