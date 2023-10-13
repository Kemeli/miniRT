/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:24:25 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:24:25 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static char	validate_c_element(char *str, char type, t_rt *rt)
{
	if (type == 'c')
	{
		rt->coordinates = validate_coordinates(str);
		if (!rt->coordinates)
			return (0);
	}
	else if (type == 'n')
	{
		rt->orientation = validate_orientation(str);
		if (!rt->orientation)
			return (0);
	}
	else if (type == 'a')
	{
		rt->fov = validate_angle(str);
		if (rt->fov == -1)
			return (0);
	}
	return (1);
}

static t_tuple	set_up(t_tuple orientation)
{
	t_tuple	a;
	t_tuple	b;
	t_tuple	setup;

	a = vector(0, 0, -1);
	b = vector(0, 0, 1);
	if (compare_doubles(orientation[1], 1))
		setup = normalize(a);
	else if (compare_doubles(orientation[1], -1))
		setup = normalize(b);
	else
		setup = (vector(0, 1, 0));
	free(a);
	free(b);
	return (setup);
}

static t_camera	*set_camera(t_rt *rt)
{
	t_camera	*cam;
	t_tuple		setup;

	cam = camera(WIDTH, HEIGHT, rt->fov * M_PI / 180);
	cam->origin = point(
			rt->coordinates[0], rt->coordinates[1], rt->coordinates[2]);
	cam->orientation = rt->orientation;
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
	t_rt	*rt;

	rt = ft_calloc(1, sizeof(t_rt));
	infos = ft_split(element, ' ');
	if (count_infos(infos) != 3)
		return (invalid("invalid amount of camera infos", "be 3", infos, rt));
	if (!validate_c_element(infos[1], 'c', rt))
		return (invalid("invalid camera coordinates", COORDINATES, infos, rt));
	if (!validate_c_element(infos[2], 'n', rt))
		return (invalid("invalid camera orientation", ORIENTATION, infos, rt));
	if (!validate_c_element(infos[3], 'a', rt))
		return (invalid("invalid camera fov", FOV, infos, rt));
	free_split(infos);
	*cam = set_camera(rt);
	free_rt(rt);
	return (1);
}
