#include <minirt.h>

static char	validate_l_element(char *str, char type, t_rt *rt)
{
	if (type == 'l')
	{
		rt->l_coordinates = validate_coordinates(str);
		if (!rt->l_coordinates)
			return(error_msg("invalid light point"));
	}
	else if (type == 'b')
	{
		rt->l_brightness = is_btwen_range(str, "0", "1");
		if (!rt->l_brightness)
			return(error_msg("invalid light brightness"));
	}
	free(str);
	return(1);
}

t_point_light	*validate_l(char *element, t_rt *rt)
{
	int				i;
	int				j;
	char			*sub;
	t_point_light	*light;

	i = 1;
	i = skip_spaces(i, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	if(!validate_l_element(sub, 'l', rt))
		return(NULL);
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	if(!validate_l_element(sub, 'b', rt))
		return(NULL);
	light = point_light(
		rt->l_coordinates,
		multiply_tuple_by_scalar(color(1, 1, 1), rt->l_brightness));
	return(light);
}
