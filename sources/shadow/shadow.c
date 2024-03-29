/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:26:49 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:26:50 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	free_shadow(t_ray *r, t_intersect *intersect, t_tuple v)
{
	free(r->direction);
	free(r);
	free_intersections(intersect);
	free(v);
}

char	is_shadowed(t_world *world, t_tuple point)
{
	t_tuple		v;
	t_tuple		direction;
	t_ray		*ray;
	t_intersect	*intersect;
	t_node		*try_hit;

	try_hit = NULL;
	v = subtract(world->light->position, point);
	direction = normalize(v);
	ray = create_ray(point, direction);
	intersect = intersect_world(world, ray);
	if (intersect->count != 0)
		try_hit = hit(intersect);
	if (try_hit && try_hit->t < magnitude(v))
	{
		free_shadow(ray, intersect, v);
		return (TRUE);
	}
	free_shadow(ray, intersect, v);
	return (FALSE);
}
