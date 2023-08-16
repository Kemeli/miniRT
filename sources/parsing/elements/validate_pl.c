#include <minirt.h>

static void	get_pl_values(char *sub, char type, t_rt *rt)
{
	if (type == 'p')
	{
		rt->pl_coordinates =  validate_coordinates(sub);
		if (!rt->pl_coordinates)
			error_and_exit("invalid pl coordinates");
	}
	else if (type == 'n')
	{
		rt->pl_normal = validate_normal(sub);
		if (!rt->pl_normal)
			error_and_exit("invalid pl normal");
	}
	else if (type == 'c')
	{
		rt->pl_color = validate_color(sub);
		if(!rt->sp_color)
			return(error_and_exit("invalid pl color"));
	}
	free(sub);
}

char	validate_pl(char *element, t_rt *rt)
{
	int		i;
	int		j;
	char	*sub;

	i = 2;
	i = skip_spaces(i, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	get_pl_values(sub, 'p', rt);
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	get_pl_values(sub, 'n', rt);
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	get_pl_values(sub, 'c', rt);
	// printf("pl coordinates: %f %f %f\n", rt->pl_coordinates[0], rt->pl_coordinates[1], rt->pl_coordinates[2]);
	// printf("pl normal: %f %f %f\n", rt->pl_normal[0], rt->pl_normal[1], rt->pl_normal[2]);
	// printf("pl color: %f %f %f\n", rt->pl_color[0], rt->pl_color[1], rt->pl_color[2]);
	return (1);
}
