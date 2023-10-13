/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:27:50 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:27:50 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	normalize(t_tuple v)
{
	double	x;
	double	y;
	double	z;
	double	w;
	double	length;

	length = magnitude(v);
	x = v[0] / length;
	y = v[1] / length;
	z = v[2] / length;
	w = v[3] / length;
	return (tuple(x, y, z, w));
}
