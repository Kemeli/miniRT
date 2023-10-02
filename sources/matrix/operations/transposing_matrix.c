/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transposing_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:23:44 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:23:45 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	**transpose_matrix(t_matrix matrix_a)
{
	t_matrix	result;
	int			i;
	int			j;
	int			size;

	size = get_size(matrix_a);
	result = matrix(size);
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			result[i][j] = matrix_a[j][i];
			i++;
		}
		j++;
	}
	return (result);
}
