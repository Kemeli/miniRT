#include <minirt.h>

void	set_plane_transform(t_object *obj, t_teste *aux)
{
	t_matrix	translate;
	t_matrix	transform;
	t_matrix	rotation;

	translate = translation(aux->coordinates[0],
			aux->coordinates[1],
			aux->coordinates[2]);
	rotation = get_rotation_matrix(aux->orientation);
	transform = multiply_matrix(translate, rotation);
	set_transform(obj, transform);
	free_matrix(translate);
	free_matrix(rotation);
	free_matrix(transform);
}

void	get_plane(t_teste *aux, t_world *w)
{
	t_object	*obj;

	obj = create_object('p');
	obj->material->color = color(
		aux->color[0],
		aux->color[1],
		aux->color[2]);
	obj->material->specular = 0.2;
	set_plane_transform(obj, aux);
	add_object(w, obj);
}

static char	get_pl_values(char *info, char type, t_teste *aux)
{
	if (type == 'p')
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
		if(!aux->color)
			return(0);
	}
	return (1);
}

char	validate_pl(char *element, t_world *w)
{
	char	**infos;
	t_teste	*aux;

	aux = ft_calloc(1, sizeof(t_teste));
	infos = ft_split(element, ' ');
	if (count_infos(infos) != 3)
		return(print_error("invalid amount of plane infos", infos, aux));
	if(!get_pl_values(infos[1], 'p', aux))
		return(print_error("invalid plane coordinates", infos, aux));
	if(!get_pl_values(infos[2], 'n', aux))
		return(print_error("invalid plane orientation", infos, aux));
	if(!get_pl_values(infos[3], 'c', aux))
		return(print_error("invalid plane color", infos, aux));
	get_plane(aux, w);
	free_split(infos);
	free_teste(aux);
	return (1);
}
