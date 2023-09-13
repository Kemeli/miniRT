#include <minirt.h>

void	free_camera(t_camera *camera)
{
	free_matrix(camera->transform);
	free_matrix(camera->inverse);
	free(camera);
}

t_camera	*camera(int hsize, int vsize, double field_of_view)
{
	t_camera	*camera;
	double		half_view;
	double		aspect;

	camera = ft_calloc(1, sizeof(t_camera));
	camera->hsize = hsize;
	camera->vsize = vsize;
	camera->field_of_view = field_of_view;
	camera->transform = NULL;
	half_view = tan(camera->field_of_view / 2);
	aspect = (double)hsize / (double)vsize;
	if (aspect >= 1)
	{
		camera->half_width = half_view;
		camera->half_height = half_view / aspect;
	}
	else
	{
		camera->half_width = half_view * aspect;
		camera->half_height = half_view;
	}
	camera->pixel_size = (camera->half_width * 2) / (double)hsize;
	return (camera);
}
