#include <minirt.h>

void	set_sphere_transform(t_object *obj, t_rt *rt)
{
	t_matrix	translate;
	t_matrix	scale;
	t_matrix	transform;

	translate = translation(rt->coordinates[0],
			rt->coordinates[1],
			rt->coordinates[2]);
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
	obj->sphere->radius = rt->diameter / 2;
	obj->material->color = color( //passar o valor diretamente?
		rt->color[0],
		rt->color[1],
		rt->color[2]);
	set_sphere_transform(obj, rt);
	add_object(w, obj);
}

static char	get_sp_values(char *info, t_rt *rt, char type)
{
	if (type == 'm')
	{
		rt->coordinates = validate_coordinates(info);
		if(!rt->coordinates)
			return(0);
	}
	else if (type == 'd')
	{
		rt->diameter = verify_and_get_double(info);
		if(!rt->diameter)
			return(0);
	}
	else if (type == 'c')
	{
		rt->color = validate_color(info);
		if(!rt->color)
			return(0);
	}
	return (1);
}

char	validate_sp(char *element, t_world *w)
{
	char		**infos;
	t_rt		*rt;

	rt = ft_calloc(1, sizeof(t_rt));
	infos = ft_split(element, ' ');
	if (count_infos(infos) != 3)
		return(print_error("invalid amount of sphere infos", infos, rt));
	if(!get_sp_values(infos[1], rt, 'm'))
		return(print_error("invalid sphere coordinates", infos, rt));
	if(!get_sp_values(infos[2], rt, 'd'))
		return(print_error("invalid sphere diameter", infos, rt));
	if(!get_sp_values(infos[3], rt, 'c'))
		return(print_error("invalid sphere color", infos, rt));
	get_sphere(rt, w);
	free_split(infos);
	free_rt(rt);
	return (1);
}
