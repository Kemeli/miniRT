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

t_tuple	set_up(t_tuple orientation)
{
	if (compare_doubles(orientation[1], 1))
		return (normalize(vector(0, 0, -1)));
	if (compare_doubles(orientation[1], -1))
		return (normalize(vector(0, 0, 1)));
	return (vector(0, 1, 0));
}

t_camera	*set_camera(t_rt *rt)
{
	t_camera	*cam;
	t_tuple		setup;

	cam = camera(WIDTH, HEIGHT, rt->c_fov * M_PI / 180);
	cam->origin = rt->c_coordinates;
	// if (!is_normalized(rt->c_normal))
	// {
	// 	normalized = normalize(rt->c_normal);
	// 	free(rt->c_normal);
	// 	rt->c_normal = normalized;
	// }
	cam->orientation = rt->c_normal;
	// free(cam->transform);
	setup = set_up(cam->orientation);
	cam->transform = view_transform(cam->origin, cam->orientation,
			setup);
	cam->inverse = inverse(cam->transform);
	free(setup);
	return (cam);
}

t_camera	*validate_c(char *element, t_rt *rt)
{
	char		**sub;

	sub = ft_split(element, ' ');
	if (count_infos(sub) != 3)
	{
		printf("count infos: %d\n", count_infos(sub));
		error_msg("invalid amount of camera infos");
		free_split(sub);
		return(NULL);
	}
	if(!validate_c_element(sub[1], 'c', rt))
	{
		free_split(sub);
		return(NULL);
	}
	if(!validate_c_element(sub[2], 'n', rt))
	{
		free_split(sub);
		return(NULL);
	}
	if(!validate_c_element(sub[3], 'a', rt))
	{
		free_split(sub);
		return(NULL);
	}
	free_split(sub);
	return (set_camera(rt));
}
