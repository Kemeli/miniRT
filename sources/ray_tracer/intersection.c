/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:26:04 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:26:04 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_node	*new_intersection(double t, t_object *object)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	node->t = t;
	node->object = object;
	node->next = NULL;
	return (node);
}

void	free_intersections(t_intersect *list)
{
	t_node	*aux;

	while (list->head)
	{
		aux = list->head;
		list->head = list->head->next;
		free(aux);
	}
	free(list);
}

t_intersect	*intersect(t_object *object, t_ray *ray)
{
	t_ray		*saved_ray;
	t_intersect	*intersect;

	saved_ray = transform_ray(ray, object->inverse);
	intersect = NULL;
	if (object->shape == 's')
		intersect = intersect_sphere(object, saved_ray);
	else if (object->shape == 'p')
		intersect = intersect_plane(object, saved_ray);
	else if (object->shape == 'c')
		intersect = intersect_cylinder(object, saved_ray);
	free_ray(saved_ray);
	return (intersect);
}
