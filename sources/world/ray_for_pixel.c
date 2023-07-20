#include <minirt.h>

t_tuple static	get_pixel(t_camera *c, float px, float py, t_matrix inv);
t_tuple static	get_origin(t_matrix inv);

t_ray	*ray_for_pixel(t_camera *c, float px, float py)
{
	t_tuple		pixel;
	t_tuple		origin;
	t_tuple		direction;
	t_tuple		sub;
	t_matrix	inv;

	inv = inverse(c->transform);
	pixel = get_pixel(c, px, py, inv);
	origin = get_origin(inv);
	sub = subtract(pixel, origin);
	direction = normalize(sub);

	free_matrix(inv);
	free(pixel);
	free(sub);
	return (create_ray(origin, direction));
}

t_tuple static	get_origin(t_matrix inv)
{
	t_tuple		p;
	t_tuple		origin;

	p = point(0, 0, 0);
	origin = multiply_matrix_with_tuple(inv, p);
	free(p);
	return (origin);
}

t_tuple static	get_pixel(t_camera *c, float px, float py, t_matrix inv)
{
	float		offset_xy[2];
	float		world_xy[2];
	t_tuple		p;
	t_tuple		pixel;

	offset_xy[0] = (px + 0.5) * c->pixel_size;
	offset_xy[1] = (py + 0.5) * c->pixel_size;
	world_xy[0] = c->half_width - offset_xy[0];
	world_xy[1] = c->half_height - offset_xy[1];

	p = point(world_xy[0], world_xy[1], -1);
	pixel = multiply_matrix_with_tuple(inv, p);
	free(p);
	return (pixel);
}
