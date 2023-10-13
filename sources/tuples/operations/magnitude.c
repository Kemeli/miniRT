/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:27:38 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:27:39 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	magnitude(t_tuple v)
{
	double	x_squared;
	double	y_squared;
	double	z_squared;
	double	w_squared;
	double	result;

	x_squared = pow(v[0], 2);
	y_squared = pow(v[1], 2);
	z_squared = pow(v[2], 2);
	w_squared = pow(v[3], 2);
	result = sqrt(x_squared + y_squared + z_squared + w_squared);
	return (result);
}
