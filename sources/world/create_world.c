/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:28:11 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:28:12 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	append_object(t_object **head, t_object **new)
{
	t_object	*aux;

	if (!*head)
	{
		*head = *new;
		return ;
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	aux->next = *new;
}

void	add_object(t_world *w, t_object *obj)
{
	if (!w->head)
		w->head = obj;
	else
		append_object(&w->head, &obj);
}

t_world	*create_world(void)
{
	t_world	*world;

	world = ft_calloc(1, sizeof(t_world));
	world->head = NULL;
	world->light = NULL;
	return (world);
}
