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
	cam->orientation = rt->c_normal;
	setup = set_up(cam->orientation);
	cam->transform = view_transform(
		cam->origin, cam->orientation, setup);
	cam->inverse = inverse(cam->transform);
	free(setup);
	return (cam);
}

void	*camera_error(char **infos)
{
	free_split(infos);
	return (NULL);
}

t_camera	*validate_c(char *element, t_rt *rt)
{
	char	**sub;

	sub = ft_split(element, ' ');
	if (count_infos(sub) != 3)
	{
		error_msg("invalid amount of camera infos");
		return(camera_error(sub));
	}
	if(!validate_c_element(sub[1], 'c', rt))
		return(camera_error(sub));
	if(!validate_c_element(sub[2], 'n', rt))
		return(camera_error(sub));
	if(!validate_c_element(sub[3], 'a', rt))
		return(camera_error(sub));
	free_split(sub);
	return (set_camera(rt));
}
