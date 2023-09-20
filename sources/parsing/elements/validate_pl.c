#include <minirt.h>

void	set_plane_transform(t_object *obj, t_rt *rt)
{
	t_matrix	translate;
	t_matrix	transform;
	t_matrix	rotation;

	translate = translation(rt->pl_coordinates[0],
			rt->pl_coordinates[1],
			rt->pl_coordinates[2]);
	rotation = get_rotation_matrix(rt->pl_orientation_v);
	transform = multiply_matrix(translate, rotation);
	set_transform(obj, transform);
	free_matrix(translate);
	free_matrix(rotation);
	free_matrix(transform);
}

void	get_plane(t_rt *rt, t_world *w)
{
	t_object	*obj;

	obj = create_object('p');
	obj->material->color = color(
		rt->pl_color[0],
		rt->pl_color[1],
		rt->pl_color[2]);
	obj->material->specular = 0.2;
	set_plane_transform(obj, rt);
	add_object(w, obj);
}

static char	get_pl_values(char *info, char type, t_rt *rt)
{
	if (type == 'p')
	{
		rt->pl_coordinates = validate_coordinates(info);
		if (!rt->pl_coordinates)
			return(0);
	}
	else if (type == 'n')
	{
		rt->pl_orientation_v = validate_orientation(info);
		if (!rt->pl_orientation_v)
			return(0);
	}
	else if (type == 'c')
	{
		rt->pl_color = validate_color(info);
		if(!rt->pl_color)
			return(0);
	}
	return (1);
}

char	validate_pl(char *element, t_rt *rt, t_world *w)
{
	char	**infos;

	infos = ft_split(element, ' ');
	if (count_infos(infos) != 3)
		return(input_error("invalid amount of plane infos", infos));
	if(!get_pl_values(infos[1], 'p', rt))
		return(input_error("invalid plane coordinates", infos));
	if(!get_pl_values(infos[2], 'n', rt))
		return(input_error("invalid plane orientation", infos));
	if(!get_pl_values(infos[3], 'c', rt))
		return(input_error("invalid plane color", infos));
	get_plane(rt, w);
	free_split(infos);
	return (1);
}
