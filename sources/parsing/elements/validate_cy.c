#include <minirt.h>

static void	check_for_errors(char *error_msg, t_tuple element)
{
	if (!element)
		error_and_exit(error_msg);
}

static char	check_tuples(char *sub, t_rt *rt, char type)
{
	if (type == 'm')
	{
		rt->cy_coordinates =  validate_coordinates(sub);
		check_for_errors("invalid cy coordinates", rt->cy_coordinates);
		return (1);
	}
	else if (type == 'n')
	{
		rt->cy_normal = validate_normal(sub);
		check_for_errors("invalid cy normal", rt->cy_normal);
		return (1);
	}
	else if (type == 'c')
	{
		rt->cy_color = validate_color(sub);
		check_for_errors("invalid cy color", rt->cy_color);
		return (1);
	}
	return (0);
}

static void	get_cy_values(char *sub, t_rt *rt, char type)
{
	if (!check_tuples(sub, rt, type))
	{
		if (type == 'd')
		{
			rt->cy_diameter = verify_and_get_float(sub);
			if (!rt->cy_diameter)
				error_and_exit("invalid cy diameter");
		}
		else if (type == 'h')
		{
			rt->cy_height = verify_and_get_float(sub);
			if (!rt->cy_height)
				error_and_exit("invalid cy height");
		}
	}
	free(sub);
}

char	validate_cy(char *element, t_rt *rt)
{
	int		i;
	int		j;
	char	*sub;

	i = skip_spaces(2, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	get_cy_values(sub, rt, 'm');
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	get_cy_values(sub, rt, 'n');
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	get_cy_values(sub, rt, 'd');
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	get_cy_values(sub, rt, 'h');
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	get_cy_values(sub, rt, 'c');
	printf("cy_coordinates: %f %f %f\n", rt->cy_coordinates[0], rt->cy_coordinates[1], rt->cy_coordinates[2]);
	printf("cy_normal: %f %f %f\n", rt->cy_normal[0], rt->cy_normal[1], rt->cy_normal[2]);
	printf("cy_diameter: %f\n", rt->cy_diameter);
	printf("cy_height: %f\n", rt->cy_height);
	printf("cy_color: %f %f %f\n", rt->cy_color[0], rt->cy_color[1], rt->cy_color[2]);
	return (1);
}
