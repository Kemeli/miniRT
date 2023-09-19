#include <minirt.h>

static char	validate_c_element(char *str, char type, t_rt *rt)
{
	if (type == 'c')
	{
		rt->c_coordinates = validate_coordinates(str);
		if (!rt->c_coordinates)
			return(0);
	}
	else if (type == 'n')
	{
		rt->c_orientation = validate_orientation(str);
		if (!rt->c_orientation)
			return(0);
	}
	else if (type == 'a')
	{
		rt->c_fov = validate_angle(str);
		if (!rt->c_fov)
			return(0);
	}
	return (1);
}

static t_tuple	set_up(t_tuple orientation)
{
	if (compare_doubles(orientation[1], 1))
		return (normalize(vector(0, 0, -1)));
	if (compare_doubles(orientation[1], -1))
		return (normalize(vector(0, 0, 1)));
	return (vector(0, 1, 0));
}

static t_camera	*set_camera(t_rt *rt)
{
	t_camera	*cam;
	t_tuple		setup;

	cam = camera(WIDTH, HEIGHT, rt->c_fov * M_PI / 180);
	cam->origin = rt->c_coordinates;
	cam->orientation = rt->c_orientation;
	setup = set_up(cam->orientation);
	cam->transform = view_transform(
		cam->origin, cam->orientation, setup);
	cam->inverse = inverse(cam->transform);
	free(setup);
	return (cam);
}

char	validate_c(char *element, t_rt *rt, t_camera **cam)
{
	char	**infos;

	infos = ft_split(element, ' ');
	if (count_infos(infos) != 3)
		return(input_error("invalid amount of camera infos", infos));
	if(!validate_c_element(infos[1], 'c', rt))
		return(input_error("invalid camera coordinates", infos));
	if(!validate_c_element(infos[2], 'n', rt))
		return(input_error("invalid camera orientation", infos));
	if(!validate_c_element(infos[3], 'a', rt))
		return(input_error("invalid camera fov", infos));
	free_split(infos);
	*cam = set_camera(rt);
	return (1);
}
