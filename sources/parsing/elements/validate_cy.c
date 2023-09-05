#include <minirt.h>

void	set_cylinder_trnasform(t_object *obj)
{
	t_matrix	translate;
	t_matrix	scale;
	t_matrix	rotate;
	t_matrix	tmp;

	translate = translation(obj->cylinder->center[0],
			obj->cylinder->center[1],
			obj->cylinder->center[2]);
	scale = scaling(obj->cylinder->radius, 1, obj->cylinder->radius);
	rotate = get_rotation_matrix(obj->normal);
	tmp = multiply_matrix(translate, rotate);
	set_transform(obj, multiply_matrix(tmp, scale));
	free_matrix(translate);
	free_matrix(scale);
	free_matrix(rotate);
	free_matrix(tmp);
}

void	get_cylinder(t_rt *rt, t_world *w)
{
	t_object	*obj;

	obj = create_object('c');
	obj->material->color = color(
		rt->cy_color[0],
		rt->cy_color[1],
		rt->cy_color[2]);
	obj->normal = vector(
		rt->cy_orientation_v[0],
		rt->cy_orientation_v[1],
		rt->cy_orientation_v[2]);
	obj->cylinder->center = point(
		rt->cy_coordinates[0],
		rt->cy_coordinates[1],
		rt->cy_coordinates[2]);
	obj->cylinder->radius = rt->cy_diameter / 2; //como usar esse valor?
	obj->cylinder->maximum = rt->cy_coordinates[1] + rt->cy_height / 2; //precisa dessa soma?
	obj->cylinder->minimum = rt->cy_coordinates[1] - rt->cy_height / 2;
	set_cylinder_trnasform(obj);
	add_object(w, obj);
	free(rt->cy_coordinates);
	free(rt->cy_orientation_v);
	free(rt->cy_color);
}

static char	check_errors(char *msg, t_tuple element)
{
	if (!element)
		return(error_msg(msg));
	return(1);
}

static char	check_tuples(char *sub, t_rt *rt, char type)
{
	if (type == 'm')
	{
		rt->cy_coordinates =  validate_coordinates(sub);
		return(check_errors("invalid cy coordinates", rt->cy_coordinates));
	}
	else if (type == 'n')
	{
		rt->cy_orientation_v = validate_normal(sub);
		return(check_errors("invalid cy normal", rt->cy_orientation_v));
	}
	else if (type == 'c')
	{
		rt->cy_color = validate_color(sub);
		return(check_errors("invalid cy color", rt->cy_color));
	}
	return (error_msg("invalid cy information"));
}

static char	get_cy_values(char *sub, t_rt *rt, char type)
{
	char	ret;

	ret = 1;
	if (type == 'd')
	{
		rt->cy_diameter = verify_and_get_double(sub);
		if (!rt->cy_diameter)
			ret = error_msg("invalid cy diameter");
	}
	else if (type == 'h')
	{
		rt->cy_height = verify_and_get_double(sub);
		if (!rt->cy_height)
			ret = error_msg("invalid cy height");
	}
	else
		ret = check_tuples(sub, rt, type);
	return (ret);
}

char	validate_cy(char *element, t_rt *rt, t_world *w)
{
	char	**sub;

	sub = ft_split(element, ' ');
	if(!get_cy_values(sub[1], rt, 'm'))
	{
		free_split(sub);
		return (0);
	}
	if(!get_cy_values(sub[2], rt, 'n'))
	{
		free_split(sub);
		return (0);
	}
	if(!get_cy_values(sub[3], rt, 'd'))
	{
		free_split(sub);
		return (0);
	}
	if(!get_cy_values(sub[4], rt, 'h'))
	{
		free_split(sub);
		return (0);
	}
	if(!get_cy_values(sub[5], rt, 'c'))
	{
		free_split(sub);
		return (0);
	}
	get_cylinder(rt, w);
	free_split(sub);
	return (1);
}
