/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:24:30 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:24:31 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	set_cylinder_transform(t_object *obj, t_rt *rt, double radius)
{
	t_matrix	translate;
	t_matrix	transform;
	t_matrix	scale;
	t_matrix	rotate;
	t_matrix	tmp;

	translate = translation(rt->coordinates[0],
			rt->coordinates[1],
			rt->coordinates[2]);
	scale = scaling(radius, 1, radius);
	rotate = get_rotation_matrix(rt->orientation);
	tmp = multiply_matrix(translate, rotate);
	transform = multiply_matrix(tmp, scale);
	set_transform(obj, transform);
	free_matrix(transform);
	free_matrix(translate);
	free_matrix(scale);
	free_matrix(rotate);
	free_matrix(tmp);
}

void	get_cylinder(t_rt *rt, t_world *w)
{
	t_object	*obj;
	double		half_height;

	obj = create_object('c');
	obj->material->color = color(
			rt->color[0],
			rt->color[1],
			rt->color[2]);
	half_height = rt->height / 2;
	obj->cylinder->maximum = half_height;
	obj->cylinder->minimum = -half_height;
	set_cylinder_transform(obj, rt, rt->diameter / 2);
	add_object(w, obj);
}

static char	check_tuples(char *info, t_rt *rt, char type)
{
	if (type == 'm')
	{
		rt->coordinates = validate_coordinates(info);
		if (!rt->coordinates)
			return (0);
	}
	else if (type == 'n')
	{
		rt->orientation = validate_orientation(info);
		if (!rt->orientation)
			return (0);
	}
	else if (type == 'c')
	{
		rt->color = validate_color(info);
		if (!rt->color)
			return (0);
	}
	else
		return (0);
	return (1);
}

static char	get_cy_values(char *info, t_rt *rt, char type)
{
	char	ret;

	ret = 1;
	if (type == 'd')
	{
		rt->diameter = verify_and_get_double(info);
		if (!rt->diameter)
			ret = 0;
	}
	else if (type == 'h')
	{
		rt->height = verify_and_get_double(info);
		if (!rt->height)
			ret = 0;
	}
	else
		ret = check_tuples(info, rt, type);
	return (ret);
}

char	validate_cy(char *element, t_world *w)
{
	char	**infos;
	t_rt	*rt;

	rt = ft_calloc(1, sizeof(t_rt));
	infos = ft_split(element, ' ');
	if (count_infos(infos) != 5)
		return (invalid("invalid amount of cylinder infos", "be 5", infos, rt));
	if (!get_cy_values(infos[1], rt, 'm'))
		return (invalid("cylinder coordinates", COORDINATES, infos, rt));
	if (!get_cy_values(infos[2], rt, 'n'))
		return (invalid("cylinder orientation", ORIENTATION, infos, rt));
	if (!get_cy_values(infos[3], rt, 'd'))
		return (invalid("cylinder diameter", POSITIVE, infos, rt));
	if (!get_cy_values(infos[4], rt, 'h'))
		return (invalid("cylinder height", POSITIVE, infos, rt));
	if (!get_cy_values(infos[5], rt, 'c'))
		return (invalid("cylinder color", COLOR, infos, rt));
	get_cylinder(rt, w);
	free_split(infos);
	free_rt(rt);
	return (1);
}
