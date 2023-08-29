#include <minirt.h>

void	write_pixel(t_image *img, int x, int y, t_tuple color)
{
	int	pixel_offset = (y * img->line_len) + (x * (img->bpp / 8));

	img->addr[pixel_offset + 0] = color[2] * 255;
	img->addr[pixel_offset + 1] = color[1] * 255;
	img->addr[pixel_offset + 2] = color[0] * 255;
	img->addr[pixel_offset + 3] = 0;
}

void	render(t_data *data)
{
	unsigned long long	x;
	unsigned long long	y;
	t_ray	*r;
	t_tuple	to_color;

	y = 0;
	x = 0;
	while (y < ((unsigned long long)data->c->vsize))
	{
		x = 0;
		while (x < ((unsigned long long)data->c->hsize))
		{
			r = ray_for_pixel(data->c, x, y);
			to_color = color_at(data->w, r);
			free_ray(r);
			write_pixel(data->img, x, y, to_color);
			free(to_color);
			x++;
		}
		y++;
	}
}
