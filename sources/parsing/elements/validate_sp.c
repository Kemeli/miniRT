#include <minirt.h>

static void	get_sp_values(char *sub, t_rt *rt, char type)
{
	if (type == 'm')
	{
		rt->sp_coordinates = validate_coordinates(sub);
		// printf("sp_coordinates: %f %f %f\n", rt->sp_coordinates[0], rt->sp_coordinates[1], rt->sp_coordinates[2]);
		if(!rt->sp_coordinates)
			return(error_and_exit("invalid sp coordinates"));
	}
	else if (type == 'd')
	{
		rt->sp_diameter = verify_and_get_float(sub);
		// printf("sp_diameter: %f\n", rt->sp_diameter);
		if(!rt->sp_diameter)
			return(error_and_exit("invalid sp diameter"));
	}
	else if (type == 'c')
	{
		rt->sp_color = validate_color(sub);
		// printf("sp_color: %f %f %f\n", rt->sp_color[0], rt->sp_color[1], rt->sp_color[2]);
		if(!rt->sp_color)
			return(error_and_exit("invalid sp color"));
	}
	free(sub);
}

void	validate_sp(char *element, t_rt *rt)
{
	int		i;
	int		j;
	char	*sub;

	i = 2;
	i = skip_spaces(i,element);
	j = go_through_char(i,element);
	sub = ft_substr(element, i, j - i);
	get_sp_values(sub, rt, 'm');
	i = skip_spaces(j,element);
	j = go_through_char(i,element);
	sub = ft_substr(element, i, j - i);
	get_sp_values(sub, rt, 'd');
	i = skip_spaces(j,element);
	j = go_through_char(i,element);
	sub = ft_substr(element, i, j - i);
	get_sp_values(sub, rt, 'c');
}
