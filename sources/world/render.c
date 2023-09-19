#include <minirt.h>

void	write_pixel(t_image *img, int x, int y, t_tuple color)
{
	int	pixel_offset = (y * img->line_len) + (x * (img->bpp / 8));

	img->addr[pixel_offset + 0] = color[2] * 255;
	img->addr[pixel_offset + 1] = color[1] * 255;
	img->addr[pixel_offset + 2] = color[0] * 255;
	img->addr[pixel_offset + 3] = 0;
}

static void	normalize_to_color(t_tuple to_color)
{
	if (to_color[0] > 1)
		to_color[0] = 1;
	if (to_color[1] > 1)
		to_color[1] = 1;
	if (to_color[2] > 1)
		to_color[2] = 1;
}

void	render(t_data *data)
{
	int	x;
	int	y;
	t_ray	*r;
	t_tuple	to_color;

	y = 0;
	while (y < (data->c->vsize))
	{
		printf("Rendering line %d\n", y); //tirar
		x = 0;
		while (x < (data->c->hsize))
		{
			r = ray_for_pixel(data->c, x, y);
			to_color = color_at(data->w, r);
			normalize_to_color(to_color);
			free(r->direction);
			free(r);
			write_pixel(data->img, x, y, to_color);
			free(to_color);
			x++;
		}
		y++;
	}
}
