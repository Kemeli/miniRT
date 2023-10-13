/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:28:44 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/29 16:12:37 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	free_mem(t_transform_aux *aux, t_matrix orient, t_matrix transl)
{
	free(aux->normal_up);
	free(aux->left);
	free(aux->true_up);
	free(aux->neg);
	free(aux);
	(void)orient;
	(void)transl;
	free_matrix(orient);
	free_matrix(transl);
}

static t_matrix	get_orientation(t_tuple left, t_tuple true_up, t_tuple forward)
{
	t_matrix	orientation;

	orientation = matrix(4);
	orientation[0][0] = left[0];
	orientation[0][1] = left[1];
	orientation[0][2] = left[2];
	orientation[1][0] = true_up[0];
	orientation[1][1] = true_up[1];
	orientation[1][2] = true_up[2];
	orientation[2][0] = -forward[0];
	orientation[2][1] = -forward[1];
	orientation[2][2] = -forward[2];
	orientation[3][3] = 1;
	return (orientation);
}

t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_matrix			orientation;
	t_matrix			transl;
	t_matrix			transform;
	t_transform_aux		*aux;

	aux = ft_calloc(1, sizeof(t_transform_aux));
	aux->normal_up = normalize(up);
	aux->left = cross(to, aux->normal_up);
	aux->true_up = cross(aux->left, to);
	orientation = get_orientation(aux->left, aux->true_up, to);
	aux->neg = negative(from);
	transl = translation(aux->neg[0], aux->neg[1], aux->neg[2]);
	transform = multiply_matrix(orientation, transl);
	free_mem(aux, orientation, transl);
	return (transform);
}
