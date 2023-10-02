/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:26:13 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:26:13 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	light_vector(t_lighting *l)
{
	t_tuple	sub;
	t_tuple	light_v;

	sub = subtract(l->light->position, l->position);
	light_v = normalize(sub);
	free(sub);
	return (light_v);
}
