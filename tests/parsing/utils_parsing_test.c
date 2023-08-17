#include <minirt.h>
#include <minunit.h>

MU_TEST(test_count_comma)
{

	int	i0 = 0;
	int	comma0 = 0;
	int	i1 = 1;
	int	comma1 = 1;

	count_comma(&i0, &comma0);
	count_comma(&i1, &comma1);
	mu_check(comma0 == 1);
	mu_check(i0 == 1);
	mu_check(comma1 == 2);
	mu_check(i1 == 2);
}
MU_TEST(test_go_through_num)
{
	mu_check(go_through_num("1.0", 0) == 3);
	mu_check(go_through_num("1.0,", 0) == 3);
	mu_check(go_through_num("1.0,3.20", 4) == 8);
	mu_check(go_through_num("1.0,3.20", 0) == 3);
}
// MU_TEST(test_go_through_num)
// {


// }

MU_TEST_SUITE(test_utils_parsing)
{
	MU_RUN_TEST(test_count_comma);
	MU_RUN_TEST(test_go_through_num);
}