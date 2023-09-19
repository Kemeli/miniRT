#include <minirt.h>

void	set_sphere_transform(t_object *obj, t_rt *rt)
{
	t_matrix	translate;
	t_matrix	scale;
	t_matrix	transform;

	translate = translation(rt->sp_coordinates[0],
			rt->sp_coordinates[1],
			rt->sp_coordinates[2]);
	scale = scaling(
			obj->sphere->radius,
			obj->sphere->radius,
			obj->sphere->radius);
	transform = multiply_matrix(translate, scale);
	set_transform(obj, transform);
	free_matrix(translate);
	free_matrix(transform);
	free_matrix(scale);
}

void	get_sphere(t_rt *rt, t_world *w)
{
	t_object	*obj;

	obj = create_object('s');
	obj->sphere->radius = rt->sp_diameter / 2;
	obj->material->color = color( //passar o valor diretamente?
		rt->sp_color[0],
		rt->sp_color[1],
		rt->sp_color[2]);
	set_sphere_transform(obj, rt);
	add_object(w, obj);
	free(rt->sp_coordinates);
	free(rt->sp_color);
}

static char	get_sp_values(char *info, t_rt *rt, char type)
{
	if (type == 'm')
	{
		rt->sp_coordinates = validate_coordinates(info);
		if(!rt->sp_coordinates)
			return(0);
	}
	else if (type == 'd')
	{
		rt->sp_diameter = verify_and_get_double(info);
		if(!rt->sp_diameter)
			return(0);
	}
	else if (type == 'c')
	{
		rt->sp_color = validate_color(info);
		if(!rt->sp_color)
			return(0);
	}
	return (1);
}

char	validate_sp(char *element, t_rt *rt, t_world *w)
{
	char		**infos;

	infos = ft_split(element, ' ');
	if (count_infos(infos) != 3)
		return(input_error("invalid amount of sphere infos", infos));
	if(!get_sp_values(infos[1], rt, 'm'))
		return(input_error("invalid sphere coordinates", infos));
	if(!get_sp_values(infos[2], rt, 'd'))
		return(input_error("invalid sphere diameter", infos));
	if(!get_sp_values(infos[3], rt, 'c'))
		return(input_error("invalid sphere color", infos));
	get_sphere(rt, w);
	free_split(infos);
	return (1);
}
