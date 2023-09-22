#include <minirt.h>

char	**get_infos(char *element)
{
	char	**infos;

	infos = ft_split(element, ' ');
	if (count_infos(infos) != 2)
	{
		error_msg("invalid amount of ambient infos", "be 2");
		free_split(infos);
		return(0);
	}
	return (infos);
}

double	get_ratio(char *str)
{
	double	ratio;

	ratio = is_btwen_range(str, "0", "1"); //colocar essa função pra retornar -1
	if (ratio == -1)
	{
		error_msg("invalid ambient ratio", BRIGHTNESS);
		return (-1);
	}
	return (ratio);
}

t_tuple	get_color(char *str)
{
	t_tuple	color;

	color = validate_color(str);
	if (!color)
	{
		error_msg("invalid ambient color", COLOR);
		return (NULL);
	}
	return (color);
}

char	ambient_error(char **infos)
{
	free_split(infos);
	return (0);
}

char	validate_a(char *element, t_world *w)
{
	double	ratio;
	char	**infos;
	t_tuple	color;

	infos = get_infos(element);
	if (!infos)
		return (0);
	ratio = get_ratio(infos[1]);
	if (ratio == -1)
		return (ambient_error(infos));
	color = get_color(infos[2]);
	if(!color)
		return (ambient_error(infos));
	w->ambient = multiply_tuple_by_scalar(color, ratio);
	free(color);
	free_split(infos);
	return (1);
}
