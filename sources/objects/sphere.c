/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:24:12 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:24:13 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_sphere	*create_sphere(void)
{
	t_sphere	*sphere;

	sphere = ft_calloc(1, sizeof(t_sphere));
	sphere->center = point(0, 0, 0);
	sphere->radius = 1;
	return (sphere);
}

void	free_sphere(t_sphere *s)
{
	free(s->center);
	free(s);
}
