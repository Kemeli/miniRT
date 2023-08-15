#include <minirt.h>
#include <minunit.h>

MU_TEST(test_validate_color_cases)
{
	t_tuple	c1 = color(1, 0.588235, 0.831373);
	t_tuple	c2 = color(0, 0, 0);
	t_tuple	c3 = color(0, 0.003922, 0.007843);
	t_tuple	c4 = color(0, 0.588235, 0.384314);
	t_tuple	c5 = color(0.011765, 0.784314, 0);
	t_tuple	c6 = color(0.054902, 0, 0.431373);

	t_tuple result1 = validate_color("255,150,212");
	t_tuple result2 = validate_color("0,0,0");
	t_tuple result3 = validate_color("0,1,2");
	t_tuple result4 = validate_color("0,150,98");
	t_tuple result5 = validate_color("3,200,0");
	t_tuple result6 = validate_color("14,0,110");

	t_tuple result7 = validate_color("255,255,256");
	t_tuple result8 = validate_color("0,0,0,0");
	t_tuple result9 = validate_color("0,1,2,3");
	t_tuple result10 = validate_color("0,150,98,0");
	t_tuple result11 = validate_color("3,200,-5");
	t_tuple result12 = validate_color("14,0,270");
	t_tuple result13 = validate_color("14,0");
	t_tuple result14 = validate_color("1e,0");
	t_tuple result15 = validate_color("14,0");
	t_tuple result16 = validate_color("1e,,0");
	t_tuple result17 = validate_color("14,0,110,");
	t_tuple result18 = validate_color("14,0,110,5");
	t_tuple result19 = validate_color("14,0,110,5,0");


	mu_check(compare_tuples(result1, c1));
	mu_check(compare_tuples(result2, c2));
	mu_check(compare_tuples(result3, c3));
	mu_check(compare_tuples(result4, c4));
	mu_check(compare_tuples(result5, c5));
	mu_check(compare_tuples(result6, c6));

	mu_check(!result7);
	mu_check(!result8);
	mu_check(!result9);
	mu_check(!result10);
	mu_check(!result11);
	mu_check(!result12);
	mu_check(!result13);
	mu_check(!result14);
	mu_check(!result15);
	mu_check(!result16);
	mu_check(!result17);
	mu_check(!result18);
	mu_check(!result19);

	free(result1);
	free(result2);
	free(result3);
	free(result4);
	free(result5);
	free(result6);
	free(result7);
	free(result8);
	free(result9);
	free(result10);
	free(result11);
	free(result12);
	free(result13);
	free(result14);
	free(result15);
	free(result16);
	free(result17);
	free(result18);
	free(result19);

	free(c1);
	free(c2);
	free(c3);
	free(c4);
	free(c5);
	free(c6);
}

MU_TEST_SUITE(test_validate_color)
{
	MU_RUN_TEST(test_validate_color_cases);
}
