#include <minirt.h>

void	set_sphere_transform(t_object *obj, t_teste *aux)
{
	t_matrix	translate;
	t_matrix	scale;
	t_matrix	transform;

	translate = translation(aux->coordinates[0],
			aux->coordinates[1],
			aux->coordinates[2]);
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

void	get_sphere(t_teste *aux, t_world *w)
{
	t_object	*obj;

	obj = create_object('s');
	obj->sphere->radius = aux->diameter / 2;
	obj->material->color = color( //passar o valor diretamente?
		aux->color[0],
		aux->color[1],
		aux->color[2]);
	set_sphere_transform(obj, aux);
	add_object(w, obj);
}

static char	get_sp_values(char *info, t_teste *aux, char type)
{
	if (type == 'm')
	{
		aux->coordinates = validate_coordinates(info);
		if(!aux->coordinates)
			return(0);
	}
	else if (type == 'd')
	{
		aux->diameter = verify_and_get_double(info);
		if(!aux->diameter)
			return(0);
	}
	else if (type == 'c')
	{
		aux->color = validate_color(info);
		if(!aux->color)
			return(0);
	}
	return (1);
}

char	validate_sp(char *element, t_world *w)
{
	char		**infos;
	t_teste		*aux;

	aux = ft_calloc(1, sizeof(t_teste));
	infos = ft_split(element, ' ');
	if (count_infos(infos) != 3)
		return(print_error("invalid amount of sphere infos", infos, aux));
	if(!get_sp_values(infos[1], aux, 'm'))
		return(print_error("invalid sphere coordinates", infos, aux));
	if(!get_sp_values(infos[2], aux, 'd'))
		return(print_error("invalid sphere diameter", infos, aux));
	if(!get_sp_values(infos[3], aux, 'c'))
		return(print_error("invalid sphere color", infos, aux));
	get_sphere(aux, w);
	free_split(infos);
	free_teste(aux);
	return (1);
}
