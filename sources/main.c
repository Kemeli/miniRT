#include <minirt.h>

// typedef struct s_image
// {
// 	void *mlx_img;
// 	char *addr;
// 	int bpp; /* bits per pixel */
// 	int line_len;
// 	int endian;
// } t_image;

// typedef struct s_data
// {
// 	void *mlx_ptr;
// 	void *win_ptr;
// 	t_image img;
// } t_data;

// void write_pixel(t_data *data, int x, int y, t_tuple color)
// {
// 	int pixel_offset = (y * data->img->line_len) + (x * (data->img->bpp / 8));

// 	data->img->addr[pixel_offset + 0] = color[2] * 255;
// 	data->img->addr[pixel_offset + 1] = color[1] * 255;
// 	data->img->addr[pixel_offset + 2] = color[0] * 255;
// 	data->img->addr[pixel_offset + 3] = 0;
// }

// int render(t_data *data)
// {
// 	int canvas_pixels = 100;
// 	double wall_z = 10;
// 	double wall_size = 7.0;
// 	double pixel_size = wall_size / canvas_pixels;
// 	double half = wall_size / 2.0;
// 	t_tuple ray_origin = point(0, 0, -5);
// 	t_object *object;

// 	object = ft_calloc(1, sizeof(t_object));

// 	t_tuple light_position = point(-10, 10, -10); //posição que a luz bate na esfera
// 	t_tuple light_intensity = color(1, 1, 1); //como a intensidade de uma lâmpada

// 	object->sphere = create_sphere();
// 	object->sphere->material->color = color(1, 0.2, 1); //lilás

// 	for (int y = 0; y < canvas_pixels; y++)
// 	{
// 		double world_y = half - pixel_size * y; //posição do pixel no eixo y

// 		for (int x = 0; x < canvas_pixels; x++)
// 		{
// 			double world_x = -half + pixel_size * x;  //posição do pixel no eixo x

// 			t_tuple dir_position = point(world_x, world_y, wall_z); //posição do raio na esfera
// 			t_tuple direction = normalize(subtract(dir_position, ray_origin)); //direção do raio
// 			t_ray *r = create_ray(ray_origin, direction);
// 			t_intersect *xs = intersect(object, r);
// 			t_node *try_hit = hit(xs);
// 			if (try_hit)
// 			{
// 				t_lighting *lighting_s = ft_calloc(1, sizeof(t_lighting));
// 				lighting_s->material = try_hit->object->sphere->material;
// 				lighting_s->light = point_light(light_position, light_intensity);
// 				lighting_s->position = get_point_position(r, try_hit->t);
// 				lighting_s->normal = normal_at(try_hit->object, lighting_s->position);
// 				lighting_s->eye = negative(r->direction); //sem negativo não aparece o ponto de luz
// 				t_tuple to_color = lighting(lighting_s); //cor final do pixel
// 					if (to_color[0] > 1)
// 						to_color[0] = 1;
// 					if (to_color[1] > 1)
// 						to_color[1] = 1;
// 					if (to_color[2] > 1)
// 						to_color[2] = 1;
// 				write_pixel(data, x, y, to_color);
// 			}
// 		}
// 	}
// 	if (data->win_ptr != NULL)
// 		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
// 			data->img->mlx_img, 0, 0);
// 	return (0);
// }

// int	handle_keypress(int keysym, t_data *data)
// {
// 	if (keysym == XK_Escape)
// 	{
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 		data->win_ptr = NULL;
// 	}
// 	return (0);
// }




// int main(void)
// {
// 	t_camera	*c;
// 	t_world		*wolrd;

// 	c = camera(200, 125, M_PI / 2);
// 	wolrd = default_world();
// 	render(c, wolrd);
// 	return (0);
// }

void write_pixel(t_data *data, int x, int y, t_tuple color)
{
	int pixel_offset = (y * data->img->line_len) + (x * (data->img->bpp / 8));

	data->img->addr[pixel_offset + 0] = color[2] * 255;
	data->img->addr[pixel_offset + 1] = color[1] * 255;
	data->img->addr[pixel_offset + 2] = color[0] * 255;
	data->img->addr[pixel_offset + 3] = 0;
}

int render(t_data *data)
{
	// int canvas_pixels = 100;
	double wall_z = 10;
	// double wall_size = 7.0;
	// double pixel_size = wall_size / canvas_pixels;
	// double half = wall_size / 2.0;
	t_tuple ray_origin = point(0, 0, -5);

	for (int y = 0; y < data->c->vsize; y++)
	{
		double world_y = data->c->half_height - data->c->pixel_size * y; //posição do pixel no eixo y

		for (int x = 0; x < data->c->hsize; x++)
		{
			double world_x = -data->c->half_width + data->c->pixel_size * x;  //posição do pixel no eixo x

			t_tuple dir_position = point(world_x, world_y, wall_z); //posição do raio na esfera
			t_tuple direction = normalize(subtract(dir_position, ray_origin)); //direção do raio
			t_ray *r = create_ray(ray_origin, direction);
				t_tuple to_color = color_at(data->w, r);
					if (to_color[0] > 1)
						to_color[0] = 1;
					if (to_color[1] > 1)
						to_color[1] = 1;
					if (to_color[2] > 1)
						to_color[2] = 1;
				write_pixel(data, x, y, to_color);
			}
		}
	if (data->win_ptr != NULL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->mlx_img, 0, 0);
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
	t_data		data;
	t_world		*w;
	t_camera	*c;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 100, 100, "print sphere");
	data.img->mlx_img = mlx_new_image(data.mlx_ptr, 100, 100);
	data.img->addr = mlx_get_data_addr(
		data.img->mlx_img,
		&data.img->bpp,
		&data.img->line_len,
		&data.img->endian
	);

	w = default_world();
	c = camera(100, 100, M_PI / 1.2);
	data.w = w;
	data.c = c;
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);

	mlx_destroy_image(data.mlx_ptr, data.img->mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);

	return 0;
}
