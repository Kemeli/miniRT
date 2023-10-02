/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:28:33 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/27 16:13:18 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_tuple	get_pixel(t_camera *c, double px, double py, t_matrix inv)
{
	double		offset_xy[2];
	double		world_xy[2];
	t_tuple		p;
	t_tuple		pixel;

	offset_xy[0] = (px + 0.5) * c->pixel_size;
	offset_xy[1] = (py + 0.5) * c->pixel_size;
	world_xy[0] = c->half_width - offset_xy[0];
	world_xy[1] = c->half_height - offset_xy[1];
	p = point(world_xy[0], world_xy[1], -1);
	pixel = multiply_matrix_with_tuple(inv, p);
	free(p);
	return (pixel);
}

t_ray	*ray_for_pixel(t_camera *c, double px, double py)
{
	t_tuple		pixel;
	t_tuple		origin;
	t_tuple		direction;
	t_tuple		sub;

	pixel = get_pixel(c, px, py, c->inverse);
	origin = c->origin;
	sub = subtract(pixel, origin);
	direction = normalize(sub);
	free(pixel);
	free(sub);
	return (create_ray(origin, direction));
}
