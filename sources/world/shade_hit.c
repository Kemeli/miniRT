/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:28:41 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:28:42 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	shade_hit(t_world *world, t_comps *comps)
{
	t_lighting	*c_lighting;
	t_tuple		color;

	c_lighting = ft_calloc(1, sizeof(t_lighting));
	c_lighting->material = comps->object->material;
	c_lighting->light = world->light;
	c_lighting->position = comps->point;
	c_lighting->eye = comps->eye;
	c_lighting->normal = comps->normal;
	c_lighting->in_shadow = is_shadowed(world, comps->over_point);
	color = lighting(c_lighting);
	free(c_lighting);
	return (color);
}
