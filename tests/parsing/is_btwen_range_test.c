#include <minirt.h>
#include <minunit.h>

MU_TEST(test_validate_1_0)
{
	mu_check(is_btwen_range("1.0", "0.0", "1.0") == 1);
}

MU_TEST(test_validate__1_0)
{
	mu_check(is_btwen_range("-1.0", "0.0", "1.0") == 0);
}

MU_TEST(test_validate_1_9)
{
	mu_check(is_btwen_range("1.9", "0.0", "1.0") == 0);
}

MU_TEST(test_validate_0_0)
{
	mu_check(is_btwen_range("0.0", "0.0", "1.0") == 1);
}

MU_TEST(test_validate_0_9)
{
	mu_check(is_btwen_range("0.9", "0.0", "1.0") == 1);
}

MU_TEST(test_validate__1_9)
{
	mu_check(is_btwen_range("-1.9", "0.0", "1.0") == 0);
}

MU_TEST(test_validate_9_0)
{
	mu_check(is_btwen_range("9.0", "0.0", "1.0") == 0);
}

MU_TEST(test_validate__0_9)
{
	mu_check(is_btwen_range("-0.9", "0.0", "1.0") == 0);
}

MU_TEST(test_validate__0_9_)
{
	mu_check(is_btwen_range("-0.9", "-1.0", "1.0") == 1);
}

MU_TEST(test_validate_1_3_btwen_1_0_and_1_5)
{
	mu_check(is_btwen_range("1.3", "1.0", "1.5") == 1);
}

MU_TEST(test_validate_1_7_btwen_1_0_and_1_5)
{
	mu_check(is_btwen_range("1.7", "1.0", "1.5") == 0);
}

// fazer testes com letras e sem ponto

MU_TEST_SUITE(test_is_btwen_range)
{
	MU_RUN_TEST(test_validate_1_0);
	MU_RUN_TEST(test_validate__1_0);
	MU_RUN_TEST(test_validate_1_9);
	MU_RUN_TEST(test_validate_0_0);
	MU_RUN_TEST(test_validate_0_9);
	MU_RUN_TEST(test_validate__0_9);
	MU_RUN_TEST(test_validate__0_9_);
	MU_RUN_TEST(test_validate_1_3_btwen_1_0_and_1_5);
	MU_RUN_TEST(test_validate_1_7_btwen_1_0_and_1_5);
}