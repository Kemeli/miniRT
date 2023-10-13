/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrix_tuple.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:23:32 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:23:33 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	multiply_matrix_with_tuple(t_matrix matrix_a, t_tuple tuple_a)
{
	t_tuple	result;
	double	sum[4];
	double	product;
	int		row;
	int		counter;

	row = 0;
	while (row < 4)
	{
		product = 0;
		counter = 0;
		while (counter < 4)
		{
			product += matrix_a[row][counter] * tuple_a[counter];
			counter++;
		}
		sum[row] = product;
		row++;
	}
	result = tuple(sum[0], sum[1], sum[2], sum[3]);
	return (result);
}
