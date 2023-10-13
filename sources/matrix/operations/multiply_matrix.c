/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:23:40 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:23:42 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static double	multiply_elements(t_matrix matrix_a,
	t_matrix matrix_b, int i, int j)
{
	double	first;
	double	second;
	double	third;
	double	fourth;

	first = matrix_a[i][0] * matrix_b[0][j];
	second = matrix_a[i][1] * matrix_b[1][j];
	third = matrix_a[i][2] * matrix_b[2][j];
	fourth = matrix_a[i][3] * matrix_b[3][j];
	return (first + second + third + fourth);
}

t_matrix	multiply_matrix(t_matrix matrix_a, t_matrix matrix_b)
{
	int			i;
	int			j;
	t_matrix	result_matrix;

	result_matrix = matrix(4);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result_matrix[i][j] = multiply_elements(matrix_a, matrix_b, i, j);
			j++;
		}
		i++;
	}
	return (result_matrix);
}
