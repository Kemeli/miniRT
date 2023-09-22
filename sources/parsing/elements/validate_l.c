#include <minirt.h>

static char	validate_l_element(char *str, char type, t_rt *rt)
{
	if (type == 'l')
	{
		rt->coordinates = validate_coordinates(str);
		if (!rt->coordinates)
			return(0);
	}
	else if (type == 'b')
	{
		rt->brightness = is_btwen_range(str, "0", "1");
		if (rt->brightness == -1)
			return(0);
	}
	return(1);
}

char	validate_l(char *element, t_point_light **light)
{
	char		**infos;
	t_tuple		c;
	t_rt		*rt;

	rt = ft_calloc(1, sizeof(t_rt));
	infos = ft_split(element, ' ');
	if (count_infos(infos) != 3)
		return(invalid("invalid amount of light infos", "be 3", infos, rt));
	if(!validate_l_element(infos[1], 'l', rt))
		return(invalid("invalid light position", COORDINATES, infos, rt));
	if(!validate_l_element(infos[2], 'b', rt))
		return(invalid("invalid light brightness", BRIGHTNESS, infos, rt));
	c = color(1, 1, 1);
	*light = point_light(
		point(rt->coordinates[0], rt->coordinates[1], rt->coordinates[2]),
		multiply_tuple_by_scalar(c, rt->brightness));
	free_split(infos);
	free(c);
	free_rt(rt);
	return(1);
}
