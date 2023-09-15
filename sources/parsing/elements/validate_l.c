#include <minirt.h>

static char	validate_l_element(char *str, char type, t_rt *rt)
{
	if (type == 'l')
	{
		rt->l_coordinates = validate_coordinates(str);
		if (!rt->l_coordinates)
			return(0);
	}
	else if (type == 'b')
	{
		rt->l_brightness = is_btwen_range(str, "0", "1");
		if (!rt->l_brightness)
			return(0);
	}
	return(1);
}

char	light_error(char *message, char **infos)
{
	free_split(infos);
	return(error_msg(message));
}

char	validate_l(char *element, t_rt *rt, t_point_light **light)
{
	char		**infos;
	t_tuple		c;

	infos = ft_split(element, ' ');
	if (count_infos(infos) != 3) //a light vem sempre como 111
		return(light_error("invalid amount of light infos", infos));
	if(!validate_l_element(infos[1], 'l', rt))
		return(light_error("invalid light position", infos));
	if(!validate_l_element(infos[2], 'b', rt))
		return(light_error("invalid light brightness", infos));
	c = color(1, 1, 1);
	*light = point_light(
		rt->l_coordinates,
		multiply_tuple_by_scalar(c, rt->l_brightness));
	free_split(infos);
	free(c);
	return(1);
}
