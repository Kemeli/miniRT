#include <minirt.h>

void	get_sphere(t_rt *rt, t_world *w)
{
	t_object *obj;
	obj = create_object('s'); //colocar proteção de erro aqui? //colocar os valores diretamente depois
	free(obj->sphere->center);
	obj->sphere->center = point(
		rt->sp_coordinates[0],
		rt->sp_coordinates[1],
		rt->sp_coordinates[2]);
	obj->sphere->radius = rt->sp_diameter / 2;
	free(obj->material->color);
	obj->material->color = color(
		rt->sp_color[0],
		rt->sp_color[1],
		rt->sp_color[2]);
	add_object(w, obj);
	free(rt->sp_coordinates);
	free(rt->sp_color);
}

static char	get_sp_values(char *sub, t_rt *rt, char type)
{
	if (type == 'm')
	{
		rt->sp_coordinates = validate_coordinates(sub);
		// printf("sp_coordinates: %f %f %f\n", rt->sp_coordinates[0], rt->sp_coordinates[1], rt->sp_coordinates[2]);
		if(!rt->sp_coordinates)
			return(error_msg("invalid sp coordinates"));
	}
	else if (type == 'd')
	{
		rt->sp_diameter = verify_and_get_double(sub);
		// printf("sp_diameter: %f\n", rt->sp_diameter);
		if(!rt->sp_diameter)
			return(error_msg("invalid sp diameter"));
	}
	else if (type == 'c')
	{
		rt->sp_color = validate_color(sub);
		// printf("sp_color: %f %f %f\n", rt->sp_color[0], rt->sp_color[1], rt->sp_color[2]);
		if(!rt->sp_color)
			return(error_msg("invalid sp color"));
	}
	free(sub);
	return (1);
}

char	validate_sp(char *element, t_rt *rt, t_world *w)
{
	int		i;
	int		j;
	char	*sub;

	i = 2;
	i = skip_spaces(i,element);
	j = go_through_char(i,element);
	sub = ft_substr(element, i, j - i);
	if(!get_sp_values(sub, rt, 'm'))
		return(0);
	i = skip_spaces(j,element);
	j = go_through_char(i,element);
	sub = ft_substr(element, i, j - i);
	if(!get_sp_values(sub, rt, 'd'))
		return(0);
	i = skip_spaces(j,element);
	j = go_through_char(i,element);
	sub = ft_substr(element, i, j - i);
	if(!get_sp_values(sub, rt, 'c'))
		return(0);
	get_sphere(rt, w);
	return (1);
}
