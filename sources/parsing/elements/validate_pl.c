#include <minirt.h>

static t_matrix	get_x_y_rotation(t_tuple orientation)
{
	t_matrix	rotate_x;
	t_matrix	rotate_y;
	t_matrix	rotate;

	rotate_x = rotation_x(M_PI / 2);
	rotate_y = rotation_y(atan(orientation[0]/ orientation[2]));
	rotate = multiply_matrix(rotate_y, rotate_x);
	free_matrix(rotate_x);
	free_matrix(rotate_y);
	return (rotate);
}

static t_matrix	get_z_x_rotation(t_tuple orientation)
{
	t_matrix	rotate_x;
	t_matrix	rotate_z;
	t_matrix	rotate;

	rotate_x = rotation_x(atan(orientation[2] / orientation[1]));
	rotate_z = rotation_z(atan(-orientation[0] / orientation[1]));
	rotate = multiply_matrix(rotate_z, rotate_x);
	free_matrix(rotate_x);
	free_matrix(rotate_z);
	return (rotate);
}

t_matrix	get_rotation_matrix(t_tuple orientation)
{
	if (compare_tuples(vector(0, 1, 0), orientation))
		return (identity_matrix(4));
	else if (compare_tuples(vector(0, -1, 0), orientation))
		return (rotation_x(M_PI));
	else if (compare_tuples(vector(1, 0, 0), orientation))
		return (rotation_z(-M_PI / 2));
	else if (compare_tuples(vector(-1, 0, 0), orientation))
		return (rotation_z(M_PI / 2));
	else if (compare_tuples(vector(0, 0, 1), orientation))
		return (rotation_x(M_PI / 2));
	else if (compare_tuples(vector(0, 0, -1), orientation))
		return (rotation_x(-M_PI / 2));
	if (compare_doubles(orientation[1], 0))
		return (get_x_y_rotation(orientation));
	else
		return (get_z_x_rotation(orientation));
}

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
	// obj->normal = vector(
	// 	rt->pl_orientation_v[0],
	// 	rt->pl_orientation_v[1],
	// 	rt->pl_orientation_v[2]);
	// obj->plane->center = point(
	// 	rt->pl_coordinates[0],
	// 	rt->pl_coordinates[1],
	// 	rt->pl_coordinates[2]);
	set_plane_transform(obj, rt);
	add_object(w, obj);
	free(rt->pl_coordinates);
	free(rt->pl_orientation_v);
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
		rt->pl_orientation_v = validate_normal(sub);
		if (!rt->pl_orientation_v)
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
