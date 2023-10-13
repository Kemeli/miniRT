/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:24:00 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:24:01 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	free_plane(t_plane *plane)
{
	free(plane->point);
	free(plane);
}

void	free_object(t_object *object)
{
	ft_free_ptr((void *) &object->material->color);
	free(object->material);
	free_matrix(object->inverse);
	free_matrix(object->transpose_inverse);
	if (object->shape == 's')
		free_sphere(object->sphere);
	else if (object->shape == 'p')
		free_plane(object->plane);
	else if (object->shape == 'c')
		free(object->cylinder);
	free(object);
}
