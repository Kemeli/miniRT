#include <minirt.h>

void	get_plane(t_rt *rt, t_world *w)
{
	t_object	*obj;

	obj = create_object('p');
	obj->material->color = color(
		rt->pl_color[0],
		rt->pl_color[1],
		rt->pl_color[2]);
	obj->normal = vector(
		rt->pl_normalized_v[0],
		rt->pl_normalized_v[1],
		rt->pl_normalized_v[2]);
	obj->plane->plane_point = point(
		rt->pl_coordinates[0],
		rt->pl_coordinates[1],
		rt->pl_coordinates[2]);
	add_object(w, obj);
	free(rt->pl_coordinates);
	free(rt->pl_normalized_v);
	free(rt->pl_color);
}

static char	get_pl_values(char *sub, char type, t_rt *rt)
{
	if (type == 'p')
	{
		rt->pl_coordinates =  validate_coordinates(sub);
		if (!rt->pl_coordinates)
			return(error_msg("invalid pl coordinates"));
	}
	else if (type == 'n')
	{
		rt->pl_normalized_v = validate_normal(sub);
		if (!rt->pl_normalized_v)
			return(error_msg("invalid pl normal"));
	}
	else if (type == 'c')
	{
		rt->pl_color = validate_color(sub);
		if(!rt->pl_color)
			return(error_msg("invalid pl color"));
	}
	free(sub);
	return (1);
}

char	validate_pl(char *element, t_rt *rt, t_world *w)
{
	int		i;
	int		j;
	char	*sub;

	i = 2;
	i = skip_spaces(i, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	if(!get_pl_values(sub, 'p', rt))
		return (0);
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	if(!get_pl_values(sub, 'n', rt))
		return (0);
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	if(!get_pl_values(sub, 'c', rt))
		return (0);
	// printf("pl coordinates: %f %f %f\n", rt->pl_coordinates[0], rt->pl_coordinates[1], rt->pl_coordinates[2]);
	// printf("pl normal: %f %f %f\n", rt->pl_normalized_v[0], rt->pl_normalized_v[1], rt->pl_normalized_v[2]);
	// printf("pl color: %f %f %f\n", rt->pl_color[0], rt->pl_color[1], rt->pl_color[2]);
	get_plane(rt, w);
	return (1);
}
