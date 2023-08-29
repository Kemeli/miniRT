#include <minirt.h>

void	free_camera(t_camera *camera)
{
	free_matrix(camera->transform);
	free(camera);
}

t_camera	*camera(float hsize, int vsize, int field_of_view)
{
	t_camera	*camera;
	float		half_view;
	float		aspect;

	camera = ft_calloc(1, sizeof(t_camera));
	camera->hsize = hsize;
	camera->vsize = vsize;
	camera->field_of_view = field_of_view;
	camera->transform = identity_matrix(4);
	half_view = tan(camera->field_of_view / 2);
	aspect = (float)camera->hsize / (float)camera->vsize;
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
	camera->pixel_size = (camera->half_width * 2) / (float)camera->hsize;
	return (camera);
}
