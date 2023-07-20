#include <minirt.h>

typedef struct s_image
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}t_image;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_camera	*c;
	t_world		*w;
	t_image	img;
}t_data;

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
	int pixel_offset = (y * data->img.line_len) + (x * (data->img.bpp / 8));

	data->img.addr[pixel_offset + 0] = color[2] * 255;
	data->img.addr[pixel_offset + 1] = color[1] * 255;
	data->img.addr[pixel_offset + 2] = color[0] * 255;
	data->img.addr[pixel_offset + 3] = 0;
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
		while (x < data->c->hsize - 1)
		{
			r = ray_for_pixel(data->c, x, y);
			to_color = color_at(data->w, r); //cor final do pixel
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
	if (data->win_ptr != NULL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.mlx_img, 0, 0);
	return (0);
}

void	render(t_camera *camera, t_world *world)
{
	t_data	data;

	data.c = camera;
	data.w = world;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(
			data.mlx_ptr, camera->hsize,
			camera->vsize,
			"print sphere");
	data.img.mlx_img = mlx_new_image(
			data.mlx_ptr,
			camera->hsize,
			camera->vsize);
	data.img.addr = mlx_get_data_addr(
			data.img.mlx_img,
			&data.img.bpp,
			&data.img.line_len,
			&data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &canvas, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
