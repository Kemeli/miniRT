/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:23:17 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:23:18 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	minor(t_matrix matrix, int i, int j)
{
	t_matrix	m;
	double		result;

	m = submatrix(matrix, i, j);
	result = get_determinant(m);
	free_matrix(m);
	return (result);
}
