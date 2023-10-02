/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:25:37 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:25:39 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_node	*hit(t_intersect *xs)
{
	t_node	*hit;
	t_node	*aux;

	hit = NULL;
	aux = xs->head;
	while (aux)
	{
		if (aux->t > 0)
		{
			if (hit == NULL)
				hit = aux;
			else if (aux->t < hit->t)
				hit = aux;
		}
		aux = aux->next;
	}
	return (hit);
}
