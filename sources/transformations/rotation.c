/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:26:54 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:26:55 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	**rotation_x(double radian)
{
	double	**rotation_matrix;

	rotation_matrix = identity_matrix(4);
	rotation_matrix[1][1] = cos(radian);
	rotation_matrix[1][2] = -sin(radian);
	rotation_matrix[2][1] = sin(radian);
	rotation_matrix[2][2] = cos(radian);
	return (rotation_matrix);
}

double	**rotation_y(double radian)
{
	double	**rotation_matrix;

	rotation_matrix = identity_matrix(4);
	rotation_matrix[0][0] = cos(radian);
	rotation_matrix[0][2] = sin(radian);
	rotation_matrix[2][0] = -sin(radian);
	rotation_matrix[2][2] = cos(radian);
	return (rotation_matrix);
}

double	**rotation_z(double radian)
{
	double	**rotation_matrix;

	rotation_matrix = identity_matrix(4);
	rotation_matrix[0][0] = cos(radian);
	rotation_matrix[0][1] = -sin(radian);
	rotation_matrix[1][0] = sin(radian);
	rotation_matrix[1][1] = cos(radian);
	return (rotation_matrix);
}
