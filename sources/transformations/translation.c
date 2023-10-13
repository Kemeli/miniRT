/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:27:11 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:27:12 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	**translation(double x, double y, double z)
{
	double	**translation_matrix;

	translation_matrix = identity_matrix(4);
	translation_matrix[0][3] = x;
	translation_matrix[1][3] = y;
	translation_matrix[2][3] = z;
	return (translation_matrix);
}
