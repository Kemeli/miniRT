#include <minirt.h>

static void	validate_l_element(char *str, char type, t_rt *rt)
{
	// if (type == 'c')
	// {
	// 	rt->L_color = validate_color(str);
	// 	if (!rt->L_color)
	// 		error_and_exit("invalid A color");
	// }
	if (type == 'l')
	{
		rt->L_coordinates = validate_coordinates(str);
		if (!rt->L_coordinates)
			error_and_exit("invalid A light point");
	}
	else if (type == 'b')
	{
		rt->L_brightness = is_btwen_range(str, "0", "1");
		if (!rt->L_brightness)
			error_and_exit("invalid A brightness");
	}
	free(str);
}

void	validate_l(char *element, t_rt *rt)
{
	int		i;
	int		j;
	char	*sub;

	i = 1;
	i = skip_spaces(i, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	validate_l_element(sub, 'l', rt);
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	validate_l_element(sub, 'b', rt);
	// i = skip_spaces(j, element);
	// j = go_through_char(i, element);
	// sub = ft_substr(element, i, j - i);
	// validate_l_element(sub, 'c', rt);
	// printf("\nL_coordinates: %f %f %f\n", rt->L_coordinates[0], rt->L_coordinates[1], rt->L_coordinates[2]);
	// printf("L_brightness: %f\n", rt->L_brightness);
	// printf("L_color: %f %f %f\n", rt->L_color[0], rt->L_color[1], rt->L_color[2]);
}
