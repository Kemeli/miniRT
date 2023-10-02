/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:29:12 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:29:13 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	free_scene(t_data *data)
{
	free_world(data->w);
	if (data->c)
		free_camera(data->c);
}

static void	set_ambient(t_world *w)
{
	t_object	*aux;

	aux = w->head;
	while (aux)
	{
		free(aux->material->ambient);
		aux->material->ambient = w->ambient;
		aux = aux->next;
	}
}

int	make_scene(t_data *data)
{
	set_ambient(data->w);
	render (data);
	if (data->win_ptr != NULL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->mlx_img, 0, 0);
	return (0);
}
