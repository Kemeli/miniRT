/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:24:08 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:24:09 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_plane	*create_plane(void)
{
	t_plane	*plane;

	plane = ft_calloc(1, sizeof(t_plane));
	plane->point = point(0, 0, 0);
	return (plane);
}
