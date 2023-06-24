#include <minirt.h>

typedef struct s_image
{
	void *mlx_img;
	char *addr;
	int bpp; /* bits per pixel */
	int line_len;
	int endian;
} t_image;

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	t_image img;
} t_data;

void write_pixel(t_data *data, int x, int y, int color)
{
	char *pixel = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int *)pixel = color;
}

int render(t_data *data)
{
	int canvas_pixels = 100;
	double wall_z = 10;
	double wall_size = 7.0;
	double pixel_size = wall_size / canvas_pixels;
	double half = wall_size / 2.0;
	t_tuple ray_origin = point(0, 0, -5);
	t_sphere *shape;

	int color = 0xFF0000; // Red

	shape = create_sphere();
	for (int y = 0; y < canvas_pixels; y++)
	{
		double world_y = half - pixel_size * y;

		for (int x = 0; x < canvas_pixels; x++)
		{
			double world_x = -half + pixel_size * x;
			t_tuple position = point(world_x, world_y, wall_z);
			t_tuple direction = normalize(subtract(position, ray_origin));
			t_ray *r = create_ray(ray_origin, direction);
			t_intersect *xs = intersect_sphere(shape, r);

			if (hit(xs))
				write_pixel(data, x, y, color);
		}
	}

	if (data->win_ptr != NULL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

int main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 100, 100, "print sphere");
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, 100, 100);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);

	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);

	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);

	return 0;
}
