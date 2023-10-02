/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spotting_submatrices.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:23:21 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:23:22 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_size(t_matrix matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

t_matrix	submatrix(t_matrix original_matrix, int row, int col)
{
	int			i;
	int			j;
	int			size;
	t_matrix	submatrix;

	size = get_size(original_matrix);
	submatrix = matrix(size - 1);
	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - 1)
		{
			if (i < row && j < col)
				submatrix[i][j] = original_matrix[i][j];
			else if (i < row && j >= col)
				submatrix[i][j] = original_matrix[i][j + 1];
			else if (i >= row && j < col)
				submatrix[i][j] = original_matrix[i + 1][j];
			else if (i >= row && j >= col)
				submatrix[i][j] = original_matrix[i + 1][j + 1];
		}
	}
	return (submatrix);
}
