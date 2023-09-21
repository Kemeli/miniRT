#include <minirt.h>

static char	validate_c_element(char *str, char type, t_teste *aux)
{
	if (type == 'c')
	{
		aux->coordinates = validate_coordinates(str);
		if (!aux->coordinates)
			return(0);
	}
	else if (type == 'n')
	{
		aux->orientation = validate_orientation(str);
		if (!aux->orientation)
			return(0);
	}
	else if (type == 'a')
	{
		aux->fov = validate_angle(str);
		if (aux->fov == -1)
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

static t_camera	*set_camera(t_teste *aux)
{
	t_camera	*cam;
	t_tuple		setup;

	cam = camera(WIDTH, HEIGHT, aux->fov * M_PI / 180);
	cam->origin = point(
		aux->coordinates[0], aux->coordinates[1], aux->coordinates[2]);
	cam->orientation = aux->orientation;
	setup = set_up(cam->orientation);
	cam->transform = view_transform(
		cam->origin, cam->orientation, setup);
	cam->inverse = inverse(cam->transform);
	free(setup);
	return (cam);
}

char	validate_c(char *element, t_camera **cam)
{
	char	**infos;
	t_teste	*aux;

	aux = ft_calloc(1, sizeof(t_teste));
	infos = ft_split(element, ' ');
	if (count_infos(infos) != 3)
		return(print_error("invalid amount of camera infos", infos, aux));
	if(!validate_c_element(infos[1], 'c', aux))
		return(print_error("invalid camera coordinates", infos, aux));
	if(!validate_c_element(infos[2], 'n', aux))
		return(print_error("invalid camera orientation", infos, aux));
	if(!validate_c_element(infos[3], 'a', aux))
		return(print_error("invalid camera fov", infos, aux));
	free_split(infos);
	*cam = set_camera(aux);
	// free_teste(aux);
	return (1);
}
