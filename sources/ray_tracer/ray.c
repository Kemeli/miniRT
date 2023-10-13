/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:26:31 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:26:32 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	free_ray(t_ray *ray)
{
	free(ray->origin);
	free(ray->direction);
	if (ray)
		free(ray);
}

t_ray	*create_ray(t_tuple origin, t_tuple direction)
{
	t_ray	*ray;

	ray = ft_calloc(1, sizeof(t_ray));
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}
