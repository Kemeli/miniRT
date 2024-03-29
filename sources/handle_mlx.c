/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:29:04 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/28 01:35:27 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	end_minirt(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
	free(data->img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	data->win_ptr = NULL;
	free(data);
	exit(0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == ESCAPE)
		end_minirt(data);
	return (0);
}

int	repeat_image(t_data *data)
{
	mlx_put_image_to_window(
		data->mlx_ptr, data->win_ptr, data->img->mlx_img, 0, 0);
	return (0);
}

void	set_mlx_hooks(t_data *data)
{
	mlx_expose_hook(data->win_ptr, repeat_image, data);
	mlx_hook(data->win_ptr, KEY_PRESS, 4, &handle_keypress, data);
	mlx_hook(data->win_ptr, DESTROY_NOTIFY, 1, &end_minirt, data);
}

char	start_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		printf("Error\n");
		printf("null mlx_ptr\n");
		return (0);
	}
	data->img = ft_calloc(1, sizeof(t_image));
	data->img->mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img->addr = mlx_get_data_addr(
			data->img->mlx_img,
			&data->img->bpp,
			&data->img->line_len,
			&data->img->endian
			);
	return (1);
}
