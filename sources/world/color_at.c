/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:28:07 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/29 16:13:06 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_tuple	get_final_color(t_comps *comps, t_world *w)
{
	t_tuple	first_c;
	t_tuple	middle_c;
	t_tuple	final_c;

	first_c = multiply_colors(
			comps->object->material->color, comps->object->material->ambient);
	middle_c = shade_hit(w, comps);
	final_c = tuple_addition(first_c, middle_c);
	free(first_c);
	free(middle_c);
	return (final_c);
}

t_tuple	color_at(t_world *w, t_ray *r)
{
	t_intersect	*xs;
	t_comps		*comps;
	t_tuple		c;
	t_node		*the_hit;

	xs = intersect_world(w, r);
	the_hit = NULL;
	if (xs->count != 0)
		the_hit = hit(xs);
	if (the_hit)
	{
		comps = prepare_computations(the_hit, r);
		c = get_final_color(comps, w);
		free_comps(comps);
	}
	else
		c = color(0, 0, 0);
	free_intersections(xs);
	return (c);
}
