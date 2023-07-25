//código que roda a imagem corretamente:
#include <minirt.h>

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

void write_pixel(t_image *img, int x, int y, t_tuple color)
{
	int pixel_offset = (y * img->line_len) + (x * (img->bpp / 8));

	img->addr[pixel_offset + 0] = color[2] * 255;
	img->addr[pixel_offset + 1] = color[1] * 255;
	img->addr[pixel_offset + 2] = color[0] * 255;
	img->addr[pixel_offset + 3] = 0;
	// printf("\ndata->img->addr: %f %f %f\n", color[0], color[1], color[2]);
}

int canvas(t_data *data)
{
	float	x;
	float	y;
	t_ray	*r;
	t_tuple	to_color;

	y = 0;
	x = 0;
	while (y < data->c->vsize - 1)
	{
		x = 0;
		while (x < data->c->hsize - 1)
		{
			r = ray_for_pixel(data->c, x, y);
			to_color = color_at(data->w, r); //cor final do pixel
			// printf("to_color: %f %f %f\n", to_color[0], to_color[1], to_color[2]);
			// to_color = color(1, 1, 1);
			if (to_color[0] > 1)
				to_color[0] = 1;
			if (to_color[1] > 1)
				to_color[1] = 1;
			if (to_color[2] > 1)
				to_color[2] = 1;
			write_pixel(data->img, x, y, to_color);
			x++;
		}
		y++;
	}
	if (data->win_ptr != NULL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->mlx_img, 0, 0);
	return (0);
}

void	render(t_camera *camera, t_world *world)
{
	t_data	data;

	data.c = camera;
	data.w = world;
	data.img = ft_calloc(1, sizeof(t_image));
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(
			data.mlx_ptr, camera->hsize,
			camera->vsize,
			"print sphere");
	data.img->mlx_img = mlx_new_image(
			data.mlx_ptr,
			camera->hsize,
			camera->vsize);
	data.img->addr = mlx_get_data_addr(
			data.img->mlx_img,
			&data.img->bpp,
			&data.img->line_len,
			&data.img->endian);
	mlx_loop_hook(data.mlx_ptr, &canvas, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img->mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}

//codigo funcionando com o valores errados para o teste:
/*
#include <minirt.h>

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

void write_pixel(t_data *data, int x, int y, t_tuple color)
{
	int pixel_offset = (y * data->img->line_len) + (x * (data->img->bpp / 8));

	data->img->addr[pixel_offset + 0] = color[2] * 255.0;
	data->img->addr[pixel_offset + 1] = color[1] * 255.0;
	data->img->addr[pixel_offset + 2] = color[0] * 255.0;
	data->img->addr[pixel_offset + 3] = 0;

	if (x == 5 && y == 5)
	{
		printf("\ncolor: %f %f %f\n", color[2]* 255.0, color[1] * 255.0, color[0] * 255.0);
		printf("data->img->addr: %f %f %f\n", (float)data->img->addr[pixel_offset + 0], (float)data->img->addr[pixel_offset + 1], (float)data->img->addr[pixel_offset + 2]);
		// printf("pixel_offset: %d\n", pixel_offset);
		// printf("x e y att: %d %d\n", x, y);
		// printf("END!!!\n");
	}
}

t_image *render(t_data *data)
{
	float	x;
	float	y;
	t_ray	*r;
	t_tuple	to_color;

	y = 0;
	x = 0;
	data->mlx_ptr = mlx_init();
	data->img = ft_calloc(1, sizeof(t_image));
	data->img->mlx_img = mlx_new_image(
			data->mlx_ptr,
			data->c->hsize,
			data->c->vsize);
	data->img->addr = ft_calloc(1, sizeof(t_image));
	data->img->addr = mlx_get_data_addr(
			data->img->mlx_img,
			&data->img->bpp,
			&data->img->line_len,
			&data->img->endian);

	while (y < data->c->vsize)
	{
		x = 0;
		while (x < data->c->hsize)
		{
			r = ray_for_pixel(data->c, x, y);
			to_color = color_at(data->w, r); //cor final do pixel
			// to_color = color(5, 5, 5);
			if (to_color[0] > 1)
				to_color[0] = 1;
			if (to_color[1] > 1)
				to_color[1] = 1;
			if (to_color[2] > 1)
				to_color[2] = 1;
			write_pixel(data, x, y, to_color);
			x++;
		}
		y++;
	}
	return (data->img);
}
*/

// t_image	handle_mlx(t_camera *camera, t_world *world)
// {
// 	t_data	data;

// 	data.c = camera;
// 	data.w = world;
// 	data.mlx_ptr = mlx_init();
// 	data.win_ptr = mlx_new_window(
// 			data.mlx_ptr, camera->hsize,
// 			camera->vsize,
// 			"print sphere");
// 	// data.img->mlx_img = mlx_new_image(
// 	// 		data.mlx_ptr,
// 	// 		camera->hsize,
// 	// 		camera->vsize);
// 	// data.img->addr = mlx_get_data_addr(
// 	// 		data.img->mlx_img,
// 	// 		&data.img->bpp,
// 	// 		&data.img->line_len,
// 	// 		&data.img->endian);
// 	mlx_loop_hook(data.mlx_ptr, (int*)&render, &data);
// 	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
// 	mlx_loop(data.mlx_ptr);
// 	// mlx_destroy_image(data.mlx_ptr, data.img->mlx_img);
// 	mlx_destroy_display(data.mlx_ptr);
// 	free(data.mlx_ptr);
// 	return (data.img);
// }

/*ideia
pegar o tamanho da matriz de floats atraves do calculo dos pixels, alocar memoria
criar a matriz la dentro como seria a de char
ruim que vai ter um loop a mais pra isso
a inicilização da mlx image vai ser uma função, ai chamaria o get_rgb
depois passaria um novo loop para o write pixel
*/

//pra mexer:
/*
#include <minirt.h>

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

void write_pixel(t_data *data, int x, int y, t_tuple color)
{
	int pixel_offset = (y * data->img->line_len) + (x * (data->img->bpp / 8));

	data->img->addr[pixel_offset + 0] = color[2] * 255.0;
	data->img->addr[pixel_offset + 1] = color[1] * 255.0;
	data->img->addr[pixel_offset + 2] = color[0] * 255.0;
	data->img->addr[pixel_offset + 3] = 0;

	if (x == 5 && y == 5)
	{
		printf("\ncolor: %f %f %f\n", color[2]* 255.0, color[1] * 255.0, color[0] * 255.0);
		printf("data->img->addr: %f %f %f\n", (float)data->img->addr[pixel_offset + 0], (float)data->img->addr[pixel_offset + 1], (float)data->img->addr[pixel_offset + 2]);
		// printf("pixel_offset: %d\n", pixel_offset);
		// printf("x e y att: %d %d\n", x, y);
		// printf("END!!!\n");
	}
}

t_image *render(t_data *data)
{
	float	x;
	float	y;
	t_ray	*r;
	t_tuple	to_color;

	y = 0;
	x = 0;
	data->mlx_ptr = mlx_init();
	data->img = ft_calloc(1, sizeof(t_image));
	data->img->mlx_img = mlx_new_image(
			data->mlx_ptr,
			data->c->hsize,
			data->c->vsize);
	data->img->addr = ft_calloc(1, sizeof(t_image));
	data->img->addr = mlx_get_data_addr(
			data->img->mlx_img,
			&data->img->bpp,
			&data->img->line_len,
			&data->img->endian);

	while (y < data->c->vsize)
	{
		x = 0;
		while (x < data->c->hsize)
		{
			r = ray_for_pixel(data->c, x, y);
			to_color = color_at(data->w, r); //cor final do pixel
			// to_color = color(5, 5, 5);
			if (to_color[0] > 1)
				to_color[0] = 1;
			if (to_color[1] > 1)
				to_color[1] = 1;
			if (to_color[2] > 1)
				to_color[2] = 1;
			write_pixel(data, x, y, to_color);
			x++;
		}
		y++;
	}
	return (data->img);
}
*/
