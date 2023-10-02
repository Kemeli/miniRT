/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:24:05 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:24:06 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_object	*create_object(char shape)
{
	t_object	*object;

	object = ft_calloc(1, sizeof(t_object));
	object->shape = shape;
	object->material = material();
	object->inverse = NULL;
	object->transpose_inverse = NULL;
	object->next = NULL;
	if (shape == 's')
		object->sphere = create_sphere();
	if (shape == 'p')
		object->plane = create_plane();
	if (shape == 'c')
		object->cylinder = create_cylinder();
	return (object);
}
