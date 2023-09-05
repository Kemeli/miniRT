#include <minirt.h>

t_tuple static	get_pixel(t_camera *c, double px, double py, t_matrix inv);
// t_tuple static	get_origin(t_matrix inv);

t_ray	*ray_for_pixel(t_camera *c, double px, double py)
{
	t_tuple		pixel;
	t_tuple		origin;
	t_tuple		direction;
	t_tuple		sub;

	pixel = get_pixel(c, px, py, c->inverse);
	// origin = get_origin(c->inverse);
	origin = point(0.000000, 1.500000, -5.000000); //isso é temporario
	sub = subtract(pixel, origin);
	direction = normalize(sub);
	free(pixel);
	free(sub);
	return (create_ray(origin, direction));
}
// pq usar o inverse para calcular a origem?
// t_tuple static	get_origin(t_matrix inv)
// {
// 	t_tuple		p;
// 	t_tuple		origin;

// 	p = point(0, 0, 0);
// 	origin = multiply_matrix_with_tuple(inv, p);
// 	free(p);
// 	return (origin);
// }

t_tuple static	get_pixel(t_camera *c, double px, double py, t_matrix inv)
{
	double		offset_xy[2];
	double		world_xy[2];
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
