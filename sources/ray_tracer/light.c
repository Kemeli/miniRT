/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:26:09 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:26:10 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_point_light	*point_light(t_tuple position, t_tuple intensity)
{
	t_point_light	*point_light;

	point_light = ft_calloc(1, sizeof(t_point_light));
	point_light->position = position;
	point_light->intensity = intensity;
	return (point_light);
}
