#include <minirt.h>

t_ray	*ray_for_pixel(t_camera *c, float px, float py)
{
	float		xoffset;
	float		yoffset;
	float		world_x;
	float		world_y;
	t_matrix	inv;
	t_tuple		pixel;
	t_tuple		origin;
	t_tuple		direction;
	t_tuple		p1;
	t_tuple		p2;
	t_tuple		sub;

	xoffset = (px + 0.5) * c->pixel_size;
	yoffset = (py + 0.5) * c->pixel_size;
	world_x = c->half_width - xoffset;
	world_y = c->half_height - yoffset;

	inv = inverse(c->transform);
	p1 = point(world_x, world_y, -1);
	pixel = multiply_matrix_with_tuple(inv, p1);
	p2 = point(0, 0, 0);
	origin = multiply_matrix_with_tuple(inv, p2);
	sub = subtract(pixel, origin);
	direction = normalize(sub);

	free_matrix(inv);
	free(pixel);
	free(p1);
	free(p2);
	free(sub);
	return (create_ray(origin, direction));
}
