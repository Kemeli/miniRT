#include <minirt.h>

static char	validate_l_element(char *str, char type, t_rt *rt)
{
	// if (type == 'c')
	// {
	// 	rt->l_color = validate_color(str);
	// 	if (!rt->l_color)
	// 		error_msg("invalid A color");
	// }
	if (type == 'l')
	{
		rt->l_coordinates = validate_coordinates(str);
		if (!rt->l_coordinates)
			return(error_msg("invalid A light point"));
	}
	else if (type == 'b')
	{
		rt->l_brightness = is_btwen_range(str, "0", "1");
		if (!rt->l_brightness)
			return(error_msg("invalid A brightness"));
	}
	free(str);
	return(1);
}

char	validate_l(char *element, t_rt *rt)
{
	int		i;
	int		j;
	char	*sub;

	i = 1;
	i = skip_spaces(i, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	if(!validate_l_element(sub, 'l', rt))
		return(0);
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	if(!validate_l_element(sub, 'b', rt))
		return(0);
	// i = skip_spaces(j, element);
	// j = go_through_char(i, element);
	// sub = ft_substr(element, i, j - i);
	// if(!validate_l_element(sub, 'c', rt))
		// return(0);
	// printf("\nl_coordinates: %f %f %f\n", rt->l_coordinates[0], rt->l_coordinates[1], rt->l_coordinates[2]);
	// printf("l_brightness: %f\n", rt->l_brightness);
	// printf("l_color: %f %f %f\n", rt->l_color[0], rt->l_color[1], rt->l_color[2]);
	rt->c = 1;
	return (1);
}