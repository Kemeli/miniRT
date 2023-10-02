/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:23:07 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:23:08 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	determinant_2x2_matrix(t_matrix matrix)
{
	double	result;
	double	first_diagonal;
	double	second_diagonal;

	first_diagonal = matrix[0][0] * matrix[1][1];
	second_diagonal = matrix[0][1] * matrix[1][0];
	result = first_diagonal - second_diagonal;
	return (result);
}

double	get_determinant(t_matrix matrix)
{
	double	size;
	double	determ;
	int		j;

	size = get_size(matrix);
	if (size == 2)
	{
		determ = determinant_2x2_matrix(matrix);
		return (determ);
	}
	j = 0;
	determ = 0;
	while (j < size)
	{
		determ += matrix[0][j] * cofactor(matrix, 0, j);
		j++;
	}
	return (determ);
}
