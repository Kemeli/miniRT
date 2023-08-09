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

typedef struct s_rt
{
	char *scene;
	char cpy_scene[100];
}	t_rt;

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

static void	error_and_exit(char *error_message)
{
	printf ("ERROR\n");
	printf ("%s\n", error_message);
	exit (0);
}

void	input_validation(int argc)
{
	if (argc != 2)
		error_and_exit("invalid number of arguments");
}

void	extension_validation(char *scene)
{
	char	*extension;
	extension = ft_strrchr(scene, '.');
	printf("\n%s\n", extension);
	if (ft_memcmp(extension, ".rt", 3))
		error_and_exit("invalid scene extension");
}

void	get_scene(t_rt *rt)
{
	int		fd;
	int		read_count;
	char	*buffer;

	fd = open(rt->scene, O_RDONLY);
	if (fd < 0)
		error_and_exit("couldn't open fd");
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_count = read(fd, buffer, BUFFER_SIZE);
	while (read_count > 0)
	{
		buffer[read_count] = '\0';
		ft_strlcat(rt->cpy_scene, buffer, 100);
		read_count = read(fd, buffer, BUFFER_SIZE);
	}
	if(rt->cpy_scene[0] == '\0')
		error_and_exit("scene is empty");
	if (close(fd) == -1)
		error_and_exit("couldn't close fd");
	free(buffer);
	return ;
}

void	validate_A(char *A_line)
{
	char	*ratio;
	int		i;
	int		j;
	char	*trimmed;

	i = 0;
	trimmed = ft_strtrim(A_line, " \t\n\v\f\r");
	j = i + 2;
	if (trimmed[i] && trimmed[i] == '-')
		j++;
	ratio = ft_substr(trimmed, i, j);
	if (!is_btwen_range(ratio))
		error_and_exit("invalid A line");
	while (trimmed[j] && trimmed[j] == ' ')
		j++;
	if(!validate_color(trimmed + j))
		error_and_exit("invalid A line");
}

int	validate_identifier(char *line)
{
	if (line && line[0] && line[1] && line[2])
	{
		if (line[0] == 'A' && line[1] == ' ')
			validate_A(line);
		else if (line[i] == 'C' && line[1] == ' ')
			return (C);
		else if (line[i] == 'L' && line[1] == ' ')
			return (L);
		else if (line[i] == 's' && line[1] == 'p' && line[2] == ' ')
			return (sp);
		else if (line[i] == 'pl' && line[1] == 'l' && line[2] == ' ')
			return (pl);
		else if (line[i] == 'cy' && line[1] == 'y' && line[2] == ' ')
			return (cy);
	}
	return (error);
}

void	validate_scene(t_rt *rt)
{
	char		*trimmed;
	char		**matrix;

	trimmed = ft_strtrim(rt->cpy_scene, " \t\n\v\f\r");
	matrix = ft_split(rt->cpy_scene, '\n');

	while(matrix[i])
	{
		if (!check_identifier(matrix[i]))
			error_and_exit("invalid identifier");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_rt	rt;

	input_validation(argc);
	rt.scene = ft_strdup(argv[1]);
	extension_validation(rt.scene);
	get_scene(&rt);
	validate_identifier(&rt);
	printf("\n%s\n", rt.cpy_scene);
}
