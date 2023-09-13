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
	return(1);
}

t_point_light	*validate_l(char *element, t_rt *rt)
{
	char			**sub;
	t_point_light	*light;
	t_tuple			c;

	sub = ft_split(element, ' ');
	if (count_infos(sub) != 3)
	{
		error_msg("invalid amount of light infos");
		free_split(sub);
		return(NULL);
	}
	if(!validate_l_element(sub[1], 'l', rt))
	{
		free_split(sub);
		return(NULL);
	}
	if(!validate_l_element(sub[2], 'b', rt))
	{
		free_split(sub);
		return(NULL);
	}
	c = color(1, 1, 1);
	light = point_light(
		rt->l_coordinates,
		multiply_tuple_by_scalar(c, rt->l_brightness));
	free_split(sub);
	free(c);
	return(light);
}
