#include <minirt.h>

void	free_ray(t_ray *ray)
{
	free(ray->origin);
	free(ray->direction);
	if(ray)
		free(ray);
}

t_ray	*create_ray(t_tuple origin, t_tuple direction)
{
	t_ray	*ray;

	ray = ft_calloc(1, sizeof(t_ray));
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}
