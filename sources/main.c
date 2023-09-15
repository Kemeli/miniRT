#include <minirt.h>

void	free_objects_list(t_object *obj);

void	append_object(t_object **head, t_object **new)
{
	t_object	*aux;

	if (!*head)
	{
		*head = *new;
		return ;
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	aux->next = *new;
}

/*
int render_first_scene(t_data *data)
{
	t_object	*floor = create_object('p');
	floor->transform = scaling(10, 0.1, 10);
	floor->material->color = color(1, 0.9, 0.9);
	floor->material->specular = 0;
	floor->inverse = inverse(floor->transform);
	floor->transpose_inverse = transpose_matrix(floor->inverse);

	t_object *middle = create_object('s');
	middle->transform = translation(-0.5, 1, 0.5);
	middle->material->color = color(0.1, 1, 0.5);
	middle->material->diffuse = 0.7;
	middle->material->specular = 0.3;
	middle->inverse = inverse(middle->transform);
	middle->transpose_inverse = transpose_matrix(middle->inverse);

	t_object *right = create_object('s');
	right->transform = multiply_matrix(
		translation(1.5, 0.5, -0.5),
		scaling(0.5, 0.5, 0.5)
	);
	right->material->color = color(0.5, 1, 0.1);
	right->material->diffuse = 0.7;
	right->material->specular = 0.3;
	right->inverse = inverse(right->transform);
	right->transpose_inverse = transpose_matrix(right->inverse);

	t_object *left = create_object('s');
	left->transform = multiply_matrix(
		translation(-1.5, 0.33, -0.75),
		scaling(0.33, 0.33, 0.33)
	);
	left->material->color = color(1, 0.8, 0.1);
	left->material->diffuse = 0.7;
	left->material->specular = 0.3;
	left->inverse = inverse(left->transform);
	left->transpose_inverse = transpose_matrix(left->inverse);

	data->w->head = floor;
	append_object(&data->w->head, &middle);
	append_object(&data->w->head, &right);
	append_object(&data->w->head, &left);

	render(data);

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

int	repeat_image(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->mlx_img, 0, 0);
	return (0);
}

int main(void)
{
	t_data		data;
	t_world		*w;
	t_camera	*c;

	data.img = ft_calloc(1, sizeof(t_image));
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "print sphere");
	data.img->mlx_img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.img->addr = mlx_get_data_addr(
		data.img->mlx_img,
		&data.img->bpp,
		&data.img->line_len,
		&data.img->endian
	);

	w = default_world();
	c = camera(WIDTH, HEIGHT, 70 * M_PI  / 180);
	free_matrix(c->transform);
	c->transform = view_transform(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0));

	c->inverse = inverse(c->transform);
	free(w->light);
	w->light = point_light(point(-10, 10, -10), color(1, 1, 1));
	data.w = w;
	data.c = c;
	render_first_scene(&data);
	// mlx_loop_hook(data.mlx_ptr, &render_first_scene, &data);
	mlx_expose_hook(data.win_ptr, repeat_image, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);

	mlx_destroy_image(data.mlx_ptr, data.img->mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
*/
#include<stdio.h>

enum	e_scene
{
	error,
	A,
	C,
	L,
	sp,
	pl,
	cy
};

void	input_validation(int argc)
{
	if (argc != 2)
	{
		printf ("ERROR\n");
		printf ("invalid number of arguments\n");
		exit (0);
	}
}

void	extension_validation(char *scene_name)
{
	char	*extension;
	extension = ft_strrchr(scene_name, '.');
	if (!extension || ft_memcmp(extension, ".rt", 3))
	{
		printf ("ERROR\n");
		printf ("invalid scene extension\n");
		exit (0);
	}
}

void	set_amb(t_world *w)
{
	t_object *aux;

	aux = w->head;
	while (aux)
	{
		free(aux->material->ambient);
		aux->material->ambient = w->ambient;
		aux = aux->next;
	}
}

int	make_scene(t_data *data)
{
	render (data);

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
		mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
		free(data->img);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->win_ptr = NULL;
		free(data);
		exit(0);
	}
	return (0);
}

int	repeat_image(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->mlx_img, 0, 0);
	return (0);
}

void	set_mlx_hooks(t_data *data)
{
	mlx_expose_hook(data->win_ptr, repeat_image, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
}

void	free_scene(t_rt *rt, t_data *data)
{
	free_rt(rt);
	free_world(data->w);
	if(data->c)
		free_camera(data->c);
}

int	main(int argc, char **argv)
{
	t_rt	*rt;
	t_data	*data;

	rt = ft_calloc(1, sizeof(t_rt));
	input_validation(argc);
	extension_validation(argv[1]);
	data = ft_calloc(1, sizeof(t_data));

	data->w = create_world();
	if (validate_scene(rt, argv[1], data))
	{
		data->img = ft_calloc(1, sizeof(t_image));
		data->mlx_ptr = mlx_init();

		data->img->mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
		data->img->addr = mlx_get_data_addr(
			data->img->mlx_img,
			&data->img->bpp,
			&data->img->line_len,
			&data->img->endian
		);
		data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "print sphere");
		set_amb(data->w);
		make_scene(data);
		free_scene(rt, data);
		set_mlx_hooks(data);
		mlx_loop(data->mlx_ptr);
	}
	else
	{
		free_scene(rt, data);
		free(data);
	}
}
//testar arquivo invalido e arquivo vazio
