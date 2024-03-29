/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:27:26 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:27:26 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	tuple_addition(t_tuple point, t_tuple vector)
{
	t_tuple	result;
	double	x;
	double	y;
	double	z;
	double	w;

	x = point[0] + vector[0];
	y = point[1] + vector[1];
	z = point[2] + vector[2];
	w = point[3] + vector[3];
	result = tuple(x, y, z, w);
	return (result);
}
