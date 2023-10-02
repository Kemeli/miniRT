/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:26:39 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:26:40 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	set_transform(t_object *o, t_matrix transform)
{
	o->inverse = inverse(transform);
	o->transpose_inverse = transpose_matrix(o->inverse);
}
