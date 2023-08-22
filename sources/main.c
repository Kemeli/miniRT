#include <minirt.h>
/*
int render_first_scene(t_data *data)
{
	t_object	*floor = create_object('p');
	floor->transform = scaling(10, 0.1, 10);
	floor->material->color = color(1, 0.9, 0.9);
	floor->material->specular = 0;

	t_object *middle = create_object('s');
	middle->transform = translation(-0.5, 1, 0.5);
	middle->material->color = color(0.1, 1, 0.5);
	middle->material->diffuse = 0.7;
	middle->material->specular = 0.3;

	t_object *right = create_object('s');
	right->transform = multiply_matrix(
		translation(1.5, 0.5, -0.5),
		scaling(0.5, 0.5, 0.5)
	);
	right->material->color = color(0.5, 1, 0.1);
	right->material->diffuse = 0.7;
	right->material->specular = 0.3;

	t_object *left = create_object('s');
	left->transform = multiply_matrix(
		translation(-1.5, 0.33, -0.75),
		scaling(0.33, 0.33, 0.33)
	);
	left->material->color = color(1, 0.8, 0.1);
	left->material->diffuse = 0.7;
	left->material->specular = 0.3;

	data->w->head = ft_calloc(1, sizeof(t_list));
	data->w->head->content = (void *)ft_calloc(1, sizeof(t_node));

	((t_node *)data->w->head->content)->object = floor;

	t_node *node4 = ft_calloc(1, sizeof(t_node));
	node4->object = middle;

	t_node *node5 = ft_calloc(1, sizeof(t_node));
	node5->object = right;

	t_node *node6 = ft_calloc(1, sizeof(t_node));
	node6->object = left;

	ft_lstadd_back(&data->w->head, ft_lstnew(node4));
	ft_lstadd_back(&data->w->head, ft_lstnew(node5));
	ft_lstadd_back(&data->w->head, ft_lstnew(node6));

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

int main(void)
{
	t_data		data;
	t_world		*w;
	t_camera	*c;

	data.img = ft_calloc(1, sizeof(t_image));
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 200, 100, "print sphere");
	data.img->mlx_img = mlx_new_image(data.mlx_ptr, 200, 100);
	data.img->addr = mlx_get_data_addr(
		data.img->mlx_img,
		&data.img->bpp,
		&data.img->line_len,
		&data.img->endian
	);

	w = default_world();
	c = camera(200, 100, M_PI / 3);
	free_matrix(c->transform);
	c->transform = view_transform(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0));
	free(w->light);
	w->light = point_light(point(-10, 10, -10), color(1, 1, 1));
	data.w = w;
	data.c = c;
	mlx_loop_hook(data.mlx_ptr, &render_first_scene, &data);
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

void	extension_validation(t_rt *rt)
{
	char	*extension;
	extension = ft_strrchr(rt->scene_name, '.');
	if (!extension || ft_memcmp(extension, ".rt", 3))
	{
		free(rt->scene_name);
		free(rt);
		printf ("ERROR\n");
		printf ("invalid scene extension\n");
		exit (0);
	}
}

char	is_normalized(t_tuple v)
{
	float	magnitude;

	magnitude = sqrt(pow(v[0], 2) + pow(v[1], 2) + pow(v[2], 2));
	if (magnitude == 1)
		return (1);
	return (0);
}

void	creat_scene(t_rt *rt, t_world *w)
{
	t_data	*data;
	t_tuple	normalized;

	(void)w;
	data = ft_calloc(1, sizeof(t_data));
	data->c = camera(100, 100, rt->c_fov);
	data->c->field_of_view = rt->c_fov;
	free(data->c->transform);
	data->c->transform = translation(
			rt->c_coordinates[0], rt->c_coordinates[1], rt->c_coordinates[2]);
	data->c->field_of_view = rt->c_fov;
	if (!is_normalized(rt->c_normal))
	{
		normalized = normalize(rt->c_normal);
	}
}

int	main(int argc, char **argv)
{
	t_rt	*rt;
	t_world	*w;

	input_validation(argc);
	rt = ft_calloc(1, sizeof(t_rt));
	rt->scene_name = ft_strdup(argv[1]);
	extension_validation(rt);
	w = create_world();
	if (validate_scene(rt, w))
		creat_scene(rt, w);
	
	free_rt(rt);
}

//lighting é inicializado com os valores passados por parametro
//parece que o "plane" não tem valores, talvez seja interessante retir a struct dele
//deu segfault com normal do cylinder invalido
//verificar vazamento de memória quando der erro nas validations

/*

	printf("\n object 1: %c added to the scene\n", ((t_node *)w->head->content)->object->shape);
	printf("\n %f, %f, %f\n", ((t_node *)w->head->content)->object->sphere->center[0], ((t_node *)w->head->content)->object->sphere->center[1], ((t_node *)w->head->content)->object->sphere->center[2]);
	printf("\n %f\n", ((t_node *)w->head->content)->object->sphere->radius);
	printf("\n %f, %f, %f\n", ((t_node *)w->head->content)->object->material->color[0], ((t_node *)w->head->content)->object->material->color[1], ((t_node *)w->head->content)->object->material->color[2]);

	printf("\n");
	printf("\n");
	printf("\n %f, %f, %f\n", ((t_node *)w->head->next->content)->object->sphere->center[0], ((t_node *)w->head->next->content)->object->sphere->center[1], ((t_node *)w->head->next->content)->object->sphere->center[2]);
	printf("\n %f\n", ((t_node *)w->head->next->content)->object->sphere->radius);
	printf("\n object 2: %c added to the scene\n", ((t_node *)w->head->next->content)->object->shape);
	printf("\n %f, %f, %f\n", ((t_node *)w->head->next->content)->object->material->color[0], ((t_node *)w->head->next->content)->object->material->color[1], ((t_node *)w->head->next->content)->object->material->color[2]);
	printf("\n");
	printf("\n");
	printf("\n %f, %f, %f\n", ((t_node *)w->head->next->next->content)->object->plane->plane_point[0], ((t_node *)w->head->next->next->content)->object->plane->plane_point[1], ((t_node *)w->head->next->next->content)->object->plane->plane_point[2]);
	printf("\n %f, %f, %f\n", ((t_node *)w->head->next->next->content)->object->normal[0], ((t_node *)w->head->next->next->content)->object->normal[1], ((t_node *)w->head->next->next->content)->object->normal[2]);
	printf("\n object 3: %c added to the scene\n", ((t_node *)w->head->next->next->content)->object->shape);
	printf("\n %f, %f, %f\n", ((t_node *)w->head->next->next->content)->object->material->color[0], ((t_node *)w->head->next->next->content)->object->material->color[1], ((t_node *)w->head->next->next->content)->object->material->color[2]);
	printf("\n");
	printf("\n");
	printf("\n %f, %f, %f\n", ((t_node *)w->head->next->next->next->content)->object->plane->plane_point[0], ((t_node *)w->head->next->next->next->content)->object->plane->plane_point[1], ((t_node *)w->head->next->next->next->content)->object->plane->plane_point[2]);
	printf("\n %f, %f, %f\n", ((t_node *)w->head->next->next->next->content)->object->normal[0], ((t_node *)w->head->next->next->next->content)->object->normal[1], ((t_node *)w->head->next->next->next->content)->object->normal[2]);
	printf("\n object 4: %c added to the scene\n", ((t_node *)w->head->next->next->next->content)->object->shape);
	printf("\n %f, %f, %f\n", ((t_node *)w->head->next->next->next->content)->object->material->color[0], ((t_node *)w->head->next->next->next->content)->object->material->color[1], ((t_node *)w->head->next->next->next->content)->object->material->color[2]);
	printf("\n");
	printf("\n");
	printf("\n %f, %f, %f\n", ((t_node *)w->head->next->next->next->next->content)->object->material->color[0], ((t_node *)w->head->next->next->next->next->content)->object->material->color[1], ((t_node *)w->head->next->next->next->next->content)->object->material->color[2]);
	printf("\n object 5: %c added to the scene\n", ((t_node *)w->head->next->next->next->next->content)->object->shape);
	printf("\n %f, %f, %f\n", ((t_node *)w->head->next->next->next->next->content)->object->normal[0], ((t_node *)w->head->next->next->next->next->content)->object->normal[1], ((t_node *)w->head->next->next->next->next->content)->object->normal[2]);
	printf("\n %f\n", ((t_node *)w->head->next->next->next->next->content)->object->cylinder->radius);
	printf("\n %f\n", ((t_node *)w->head->next->next->next->next->content)->object->cylinder->maximum);

	printf("\n");
	printf("\n");
	printf("\n %f, %f, %f\n", ((t_node *)w->head->next->next->next->next->next->content)->object->material->color[0], ((t_node *)w->head->next->next->next->next->next->content)->object->material->color[1], ((t_node *)w->head->next->next->next->next->next->content)->object->material->color[2]);
	printf("\n object 6: %c added to the scene\n", ((t_node *)w->head->next->next->next->next->next->content)->object->shape);
	printf("\n %f, %f, %f\n", ((t_node *)w->head->next->next->next->next->next->content)->object->normal[0], ((t_node *)w->head->next->next->next->next->next->content)->object->normal[1], ((t_node *)w->head->next->next->next->next->next->content)->object->normal[2]);
	printf("\n %f\n", ((t_node *)w->head->next->next->next->next->next->content)->object->cylinder->radius);
	printf("\n %f\n", ((t_node *)w->head->next->next->next->next->next->content)->object->cylinder->maximum);*/
