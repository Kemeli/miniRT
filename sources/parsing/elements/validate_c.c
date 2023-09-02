#include <minirt.h>

static char	validate_c_element(char *str, char type, t_rt *rt)
{
	if (type == 'c')
	{
		rt->c_coordinates =  validate_coordinates(str);
		if (!rt->c_coordinates)
			return(error_msg("invalid C coordinates"));
	}
	else if (type == 'n')
	{
		rt->c_normal = validate_normal(str);
		if (!rt->c_normal)
			return(error_msg("invalid C normal"));
	}
	else if (type == 'a')
	{
		rt->c_fov = validate_angle(str);
		if (!rt->c_fov)
			return(error_msg("invalid C fov"));
	}
	free(str);
	return (1);
}

char	is_normalized(t_tuple v)
{
	double	magnitude;

	magnitude = sqrt(pow(v[0], 2) + pow(v[1], 2) + pow(v[2], 2));
	if (magnitude == 1)
		return (1);
	return (0);
}

t_camera	*set_camera(t_rt *rt)
{
	t_tuple		origin;
	t_camera	*cam;
	t_tuple		normalized;

	origin = rt->c_coordinates;
	cam = camera(WIDTH, HEIGHT, rt->c_fov * M_PI / 180);
	if (!is_normalized(rt->c_normal))
	{
		normalized = normalize(rt->c_normal);
		free(rt->c_normal);
		rt->c_normal = normalized;
	}
	free(cam->transform);
	cam->transform = view_transform(origin, rt->c_normal,
			normalize(rt->c_normal));
	return (cam);
}

t_camera	*validate_c(char *element, t_rt *rt)
{
	int			i;
	int			j;
	char		*sub;

	i = 1;
	i = skip_spaces(i, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	if(!validate_c_element(sub, 'c', rt))
		return(NULL);
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	if(!validate_c_element(sub, 'n', rt))
		return(NULL);
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	if(!validate_c_element(sub, 'a', rt))
		return(NULL);
	return (set_camera(rt));
}
