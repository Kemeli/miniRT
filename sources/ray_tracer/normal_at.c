#include <minirt.h>

static void	update_temp(t_matrix *t);

static t_tuple local_normal_at(t_object *object, t_tuple local_point)
{
	t_tuple	obj_normal;

	obj_normal = NULL;
	if(object->shape == 's')
		obj_normal = subtract(local_point, object->sphere->center);
	return (obj_normal);
} //aqui faltou transformar o obj_normal em vector, os tests passaam sem isso

t_tuple	normal_at(t_object *object, t_tuple world_point)
{
	t_tuple		normal;
	t_tuple		obj_point;
	t_tuple		obj_normal;
	t_tuple		world_normal;
	t_matrix	temp;

	temp = inverse(object->transform);
	obj_point = multiply_matrix_with_tuple(temp, world_point);
	obj_normal = local_normal_at(object, obj_point);
	update_temp(&temp);
	world_normal = multiply_matrix_with_tuple(temp, obj_normal);
	world_normal[3] = 0;
	normal = normalize(world_normal);
	free_matrix(temp);
	free(obj_normal);
	free(obj_point);
	free(world_normal);
	return (normal);
}

static void	update_temp(t_matrix *t)
{
	t_matrix	temp;

	temp = transpose_matrix(*t);
	free_matrix(*t);
	*t = temp;
}
