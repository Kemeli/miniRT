#include <minirt.h>

void	set_cylinder_transform(t_object *obj, t_rt *rt)
{
	t_matrix	translate;
	t_matrix	transform;
	t_matrix	scale;
	t_matrix	rotate;
	t_matrix	tmp;

	translate = translation(rt->cy_coordinates[0],
			rt->cy_coordinates[1],
			rt->cy_coordinates[2]);
	scale = scaling(rt->cy_diameter / 2, 1, rt->cy_diameter / 2); //rt->cy_diameter / 2 = radius
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
	// obj->cylinder->radius = rt->cy_diameter / 2;
	// obj->cylinder->maximum = rt->cy_coordinates[1] + rt->cy_height / 2; //precisa dessa soma?
	half_height = rt->cy_height / 2;
	obj->cylinder->maximum = half_height;
	// obj->cylinder->minimum = rt->cy_coordinates[1] - rt->cy_height / 2;
	obj->cylinder->minimum = -half_height;
	set_cylinder_transform(obj, rt);
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
