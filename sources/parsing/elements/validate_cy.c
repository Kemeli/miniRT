#include <minirt.h>

void	set_cylinder_trnasform(t_object *obj)
{
	free(obj->transform);
	obj->transform = multiply_matrix(
		translation(obj->cylinder->center[0], obj->cylinder->center[1], obj->cylinder->center[2]),
		multiply_matrix(
			rotation_x(M_PI / 2),
			scaling(obj->cylinder->radius, obj->cylinder->height, obj->cylinder->radius)
		)
	);
	obj->inverse = inverse(obj->transform);
	obj->transpose_inverse = transpose_matrix(obj->inverse);
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
		rt->cy_normalized_v[0],
		rt->cy_normalized_v[1],
		rt->cy_normalized_v[2]);
	obj->cylinder->center = point(
		rt->cy_coordinates[0],
		rt->cy_coordinates[1],
		rt->cy_coordinates[2]);
	obj->cylinder->radius = rt->cy_diameter / 2; //como usar esse valor?
	obj->cylinder->maximum = rt->cy_coordinates[1] + rt->cy_height / 2;
	obj->cylinder->minimum = rt->cy_coordinates[1] - rt->cy_height / 2;
	set_cylinder_trnasform(obj);
	add_object(w, obj);
	free(rt->cy_coordinates);
	free(rt->cy_normalized_v);
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
		rt->cy_normalized_v = validate_normal(sub);
		return(check_errors("invalid cy normal", rt->cy_normalized_v));
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
	free (sub);
	return (ret);
}

char	validate_cy(char *element, t_rt *rt, t_world *w)
{
	int		i;
	int		j;
	char	*sub;

	i = skip_spaces(2, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	if(!get_cy_values(sub, rt, 'm'))
		return (0);
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	if(!get_cy_values(sub, rt, 'n'))
		return (0);
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	if(!get_cy_values(sub, rt, 'd'))
		return (0);
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	if(!get_cy_values(sub, rt, 'h'))
		return (0);
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	if(!get_cy_values(sub, rt, 'c'))
		return (0);
	get_cylinder(rt, w);
	return (1);
}
