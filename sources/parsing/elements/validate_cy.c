#include <minirt.h>

void	set_cylinder_transform(t_object *obj, t_teste *aux, double radius)
{
	t_matrix	translate;
	t_matrix	transform;
	t_matrix	scale;
	t_matrix	rotate;
	t_matrix	tmp;

	translate = translation(aux->coordinates[0],
			aux->coordinates[1],
			aux->coordinates[2]);
	scale = scaling(radius, 1, radius);
	rotate = get_rotation_matrix(aux->orientation);
	tmp = multiply_matrix(translate, rotate);
	transform = multiply_matrix(tmp, scale);
	set_transform(obj, transform);
	free_matrix(transform);
	free_matrix(translate);
	free_matrix(scale);
	free_matrix(rotate);
	free_matrix(tmp);
}

void	get_cylinder(t_teste *aux, t_world *w)
{
	t_object	*obj;
	double		half_height;

	obj = create_object('c');
	obj->material->color = color(
		aux->color[0],
		aux->color[1],
		aux->color[2]);
	half_height = aux->height / 2;
	obj->cylinder->maximum = half_height;
	obj->cylinder->minimum = -half_height;
	set_cylinder_transform(obj, aux, aux->diameter / 2);
	add_object(w, obj);
}

static char	check_tuples(char *info, t_teste *aux, char type)
{
	if (type == 'm')
	{
		aux->coordinates = validate_coordinates(info);
		if (!aux->coordinates)
			return(0);
	}
	else if (type == 'n')
	{
		aux->orientation = validate_orientation(info);
		if (!aux->orientation)
			return(0);
	}
	else if (type == 'c')
	{
		aux->color = validate_color(info);
		if (!aux->color)
			return(0);
	}
	else
		return (0);
	return (1);
}

static char	get_cy_values(char *info, t_teste *aux, char type)
{
	char	ret;

	ret = 1;
	if (type == 'd')
	{
		aux->diameter = verify_and_get_double(info);
		if (!aux->diameter)
			ret = 0;
	}
	else if (type == 'h')
	{
		aux->height = verify_and_get_double(info);
		if (!aux->height)
			ret = 0;
	}
	else
		ret = check_tuples(info, aux, type);
	return (ret);
}

char	validate_cy(char *element, t_world *w)
{
	char	**infos;
	t_teste	*aux;

	aux = ft_calloc(1, sizeof(t_teste));
	infos = ft_split(element, ' ');
	if (count_infos(infos) != 5)
		return(print_error("invalid amount of cylinder infos", infos, aux));
	if(!get_cy_values(infos[1], aux, 'm'))
		return(print_error("invalid cylinder coordinates", infos, aux));
	if(!get_cy_values(infos[2], aux, 'n'))
		return(print_error("invalid cylinder orientation", infos, aux));
	if(!get_cy_values(infos[3], aux, 'd'))
		return(print_error("invalid cylinder diameter", infos, aux));
	if(!get_cy_values(infos[4], aux, 'h'))
		return(print_error("invalid cylinder height", infos, aux));
	if(!get_cy_values(infos[5], aux, 'c'))
		return(print_error("invalid cylinder color", infos, aux));
	get_cylinder(aux, w);
	free_split(infos);
	free_teste(aux);
	return (1);
}
