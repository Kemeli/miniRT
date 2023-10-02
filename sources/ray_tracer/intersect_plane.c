/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:25:55 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:25:56 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_intersect	*intersect_plane(t_object *object, t_ray *ray)
{
	t_intersect	*intersect;
	double		t;

	intersect = ft_calloc(1, sizeof(t_intersect));
	if (fabs(ray->direction[1]) < EPSILON)
		return (intersect);
	t = -ray->origin[1] / ray->direction[1];
	intersect->head = new_intersection(t, object);
	intersect->count = 1;
	return (intersect);
}
