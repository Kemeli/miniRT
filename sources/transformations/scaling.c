/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:26:58 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:26:59 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_matrix	scaling(double x, double y, double z)
{
	t_matrix	scaling_matrix;

	scaling_matrix = identity_matrix(4);
	scaling_matrix[0][0] = x;
	scaling_matrix[1][1] = y;
	scaling_matrix[2][2] = z;
	return (scaling_matrix);
}
