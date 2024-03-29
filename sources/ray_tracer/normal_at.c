/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:26:27 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:26:28 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_tuple	local_normal_at_cy(t_object *object, t_tuple local_point)
{
	double	distance;

	distance = pow(local_point[0], 2) + pow(local_point[2], 2);
	if (distance < 1 && local_point[1] >= object->cylinder->maximum - EPSILON)
		return (vector(0, 1, 0));
	else if (distance < 1
		&& local_point[1] <= object->cylinder->minimum + EPSILON)
		return (vector(0, -1, 0));
	return (vector(local_point[0], 0, local_point[2]));
}

t_tuple	local_normal_at(t_object *object, t_tuple local_point)
{
	t_tuple	obj_normal;

	obj_normal = NULL;
	if (object->shape == 's')
		obj_normal = subtract(local_point, object->sphere->center);
	if (object->shape == 'p')
		obj_normal = vector(0, 1, 0);
	if (object->shape == 'c')
		obj_normal = local_normal_at_cy(object, local_point);
	return (obj_normal);
}

t_tuple	normal_at(t_object *object, t_tuple world_point)
{
	t_tuple		normal;
	t_tuple		obj_point;
	t_tuple		obj_normal;
	t_tuple		world_normal;

	obj_point = multiply_matrix_with_tuple(object->inverse, world_point);
	obj_normal = local_normal_at(object, obj_point);
	world_normal = multiply_matrix_with_tuple(
			object->transpose_inverse,
			obj_normal);
	world_normal[3] = 0;
	normal = normalize(world_normal);
	free(obj_normal);
	free(obj_point);
	free(world_normal);
	return (normal);
}
