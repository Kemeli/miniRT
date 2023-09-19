#include <minirt.h>

void	set_cylinder_transform(t_object *obj, t_rt *rt, double radius)
{
	t_matrix	translate;
	t_matrix	transform;
	t_matrix	scale;
	t_matrix	rotate;
	t_matrix	tmp;

	translate = translation(rt->cy_coordinates[0],
			rt->cy_coordinates[1],
			rt->cy_coordinates[2]);
	scale = scaling(radius, 1, radius);
	rotate = get_rotation_matrix(rt->cy_orientation_v);
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
		rt->cy_color[0],
		rt->cy_color[1],
		rt->cy_color[2]);
	half_height = rt->cy_height / 2;
	obj->cylinder->maximum = half_height;
	obj->cylinder->minimum = -half_height;
	set_cylinder_transform(obj, rt, rt->cy_diameter / 2);
	add_object(w, obj);
	free(rt->cy_coordinates);
	free(rt->cy_orientation_v);
	free(rt->cy_color);
}

static char	check_tuples(char *info, t_rt *rt, char type)
{
	if (type == 'm')
	{
		rt->cy_coordinates = validate_coordinates(info);
		if (!rt->cy_coordinates)
			return(0);
	}
	else if (type == 'n')
	{
		rt->cy_orientation_v = validate_orientation(info);
		if (!rt->cy_orientation_v)
			return(0);
	}
	else if (type == 'c')
	{
		rt->cy_color = validate_color(info);
		if (!rt->cy_color)
			return(0);
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
		rt->cy_diameter = verify_and_get_double(info);
		if (!rt->cy_diameter)
			ret = 0;
	}
	else if (type == 'h')
	{
		rt->cy_height = verify_and_get_double(info);
		if (!rt->cy_height)
			ret = 0;
	}
	else
		ret = check_tuples(info, rt, type);
	return (ret);
}

char	validate_cy(char *element, t_rt *rt, t_world *w)
{
	char	**infos;

	infos = ft_split(element, ' ');
	if (count_infos(infos) != 5)
		return(input_error("invalid amount of cylinder infos", infos));
	if(!get_cy_values(infos[1], rt, 'm'))
		return(input_error("invalid cylinder coordinates", infos));
	if(!get_cy_values(infos[2], rt, 'n'))
		return(input_error("invalid cylinder orientation", infos));
	if(!get_cy_values(infos[3], rt, 'd'))
		return(input_error("invalid cylinder diameter", infos));
	if(!get_cy_values(infos[4], rt, 'h'))
		return(input_error("invalid cylinder height", infos));
	if(!get_cy_values(infos[5], rt, 'c'))
		return(input_error("invalid cylinder color", infos));
	get_cylinder(rt, w);
	free_split(infos);
	return (1);
}
