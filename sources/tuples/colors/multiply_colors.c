/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:27:22 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:27:23 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	multiply_colors(t_tuple c1, t_tuple c2)
{
	double	r;
	double	g;
	double	b;
	t_tuple	result;

	r = c1[0] * c2[0];
	g = c1[1] * c2[1];
	b = c1[2] * c2[2];
	result = color (r, g, b);
	return (result);
}
