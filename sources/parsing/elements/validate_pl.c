#include <minirt.h>

void	set_plane_transform(t_object *obj, t_rt *rt)
{
	t_matrix	translate;
	t_matrix	transform;
	t_matrix	rotation;

	translate = translation(rt->coordinates[0],
			rt->coordinates[1],
			rt->coordinates[2]);
	rotation = get_rotation_matrix(rt->orientation);
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
		rt->color[0],
		rt->color[1],
		rt->color[2]);
	obj->material->specular = 0.2;
	set_plane_transform(obj, rt);
	add_object(w, obj);
}

static char	get_pl_values(char *info, char type, t_rt *rt)
{
	if (type == 'p')
	{
		rt->coordinates = validate_coordinates(info);
		if (!rt->coordinates)
			return(0);
	}
	else if (type == 'n')
	{
		rt->orientation = validate_orientation(info);
		if (!rt->orientation)
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

char	validate_pl(char *element, t_world *w)
{
	char	**infos;
	t_rt	*rt;

	rt = ft_calloc(1, sizeof(t_rt));
	infos = ft_split(element, ' ');
	if (count_infos(infos) != 3)
		return(invalid("invalid amount of plane infos", "be 3", infos, rt));
	if(!get_pl_values(infos[1], 'p', rt))
		return(invalid("invalid plane coordinates", COORDINATES, infos, rt));
	if(!get_pl_values(infos[2], 'n', rt))
		return(invalid("invalid plane orientation", ORIENTATION, infos, rt));
	if(!get_pl_values(infos[3], 'c', rt))
		return(invalid("invalid plane color", COLOR, infos, rt));
	get_plane(rt, w);
	free_split(infos);
	free_rt(rt);
	return (1);
}
