#include <minirt.h>

void	set_plane_transform(t_object *obj)
{
	// t_matrix	translate;
	// t_matrix	scale;
	// t_matrix	rotation;

	// translate = translation(obj->plane->plane_point[0], obj->plane->plane_point[1], obj->plane->plane_point[2]);
	// scale = scaling(obj->cylinder->radius, 1, obj->cylinder->radius);
	// rotation = rotation_x(obj->normal);
	free(obj->transform);
	obj->transform = translation(obj->plane->plane_point[0], obj->plane->plane_point[1], obj->plane->plane_point[2]);
	obj->inverse = inverse(obj->transform);
	obj->transpose_inverse = transpose_matrix(obj->inverse);
}

void	get_plane(t_rt *rt, t_world *w)
{
	t_object	*obj;

	obj = create_object('p');
	obj->material->color = color(
		rt->pl_color[0],
		rt->pl_color[1],
		rt->pl_color[2]);
	obj->normal = vector(
		rt->pl_normalized_v[0],
		rt->pl_normalized_v[1],
		rt->pl_normalized_v[2]);
	obj->plane->plane_point = point(
		rt->pl_coordinates[0],
		rt->pl_coordinates[1],
		rt->pl_coordinates[2]);
	set_plane_transform(obj);
	add_object(w, obj);
	free(rt->pl_coordinates);
	free(rt->pl_normalized_v);
	free(rt->pl_color);
}

static char	get_pl_values(char *sub, char type, t_rt *rt)
{
	if (type == 'p')
	{
		rt->pl_coordinates =  validate_coordinates(sub);
		if (!rt->pl_coordinates)
			return(error_msg("invalid pl coordinates"));
	}
	else if (type == 'n')
	{
		rt->pl_normalized_v = validate_normal(sub);
		if (!rt->pl_normalized_v)
			return(error_msg("invalid pl normal"));
	}
	else if (type == 'c')
	{
		rt->pl_color = validate_color(sub);
		if(!rt->pl_color)
			return(error_msg("invalid pl color"));
	}
	return (1);
}

char	validate_pl(char *element, t_rt *rt, t_world *w)
{
	char	**sub;

	sub = ft_split(element, ' ');
	if(!get_pl_values(sub[1], 'p', rt))
	{
		free_split(sub);
		return (0);
	}
	if(!get_pl_values(sub[2], 'n', rt))
	{
		free_split(sub);
		return (0);
	}
	if(!get_pl_values(sub[3], 'c', rt))
	{
		free_split(sub);
		return (0);
	}
	get_plane(rt, w);
	free_split(sub);
	return (1);
}
