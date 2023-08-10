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
	if (ft_memcmp(extension, ".rt", 3))
		error_and_exit("invalid scene extension");
}

void	get_scene(t_rt *rt)
{
	int		fd;
	int		read_count;
	char	*buffer;

	fd = open(rt->scene_name, O_RDONLY);
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
//lembrar que as funções estão lidaando com numeros de  a 1
int	get_num_len(char *str, int i)
{
	while(str[i] != ',')
		i++;
	return (i);
}

t_tuple	char_to_color(char *str)
{
	char	*r;
	char	*g;
	char	*b;
	int		first_len;
	int		sec_len;
	t_tuple	rgb;

	first_len = get_num_len(str, 0);
	r = ft_substr(str, 0, first_len);
	sec_len = get_num_len(str, first_len + 1);
	g = ft_substr(str, first_len + 1, sec_len);
	b = ft_substr(str, sec_len + 1, ft_strlen(str));
	rgb = color(ft_atof(r) / 255, ft_atof(g) / 255, ft_atof(b) / 255);
	free(r);
	free(g);
	free(b);
	return (rgb);
}

void	validate_A(char *A_line, t_rt *rt)
{
	char	*ratio;
	int		i;
	int		j;
	char	*trimmed;
	char	*color;

	trimmed = ft_strtrim(A_line, " \t\n\v\f\r");
	i = 1; //começa no 1 espaço depois do A
	while(trimmed[i] && trimmed[i] == ' ')
		i++; //percorre outros espaços
	j = 3;
	ratio = ft_substr(trimmed, i, j);
	if (!is_btwen_range(ratio, "0", "1"))
		error_and_exit("invalid A ratio");
	printf("\nA_ratio: %s\n", ratio);
	while (trimmed[i + j] && trimmed[i + j] == ' ')
		j++;
	color = validate_color(trimmed + (i + j));
	if(!color)
		error_and_exit("invalid A color");
	rt->A_color = char_to_color(color);
	printf("\nA_color: %f, %f, %f\n", rt->A_color[0], rt->A_color[1], rt->A_color[2]);
	free(trimmed);
}

// void	validate_C(char *C_line, t_rt *rt)
// {
// 	char	*trimmed;
// 	int		i;

// 	trimmed = ft_strtrim(C_line, " \t\n\v\f\r");
// 	i = 1;
// 	while(trimmed[i] && trimmed[i] == ' ')
// 		i++;

// }

void	validate_identifier(char *line, t_rt *rt)
{
	if (line && line[0] && line[1] && line[2])
	{
		if (line[0] == 'A' && line[1] == ' ')
			validate_A(line, rt);
		// else if (line[i] == 'C' && line[1] == ' ')
		// 	validate_C(line, rt);
		// else if (line[i] == 'L' && line[1] == ' ')
		// 	return (L);
		// else if (line[i] == 's' && line[1] == 'p' && line[2] == ' ')
		// 	return (sp);
		// else if (line[i] == 'pl' && line[1] == 'l' && line[2] == ' ')
		// 	return (pl);
		// else if (line[i] == 'cy' && line[1] == 'y' && line[2] == ' ')
		// 	return (cy);
	}
}

void	validate_scene(t_rt *rt)
{
	char		*trimmed;
	char		**matrix;
	// int			i;

	// i = 0;
	trimmed = ft_strtrim(rt->cpy_scene, " \t\n\v\f\r");
	matrix = ft_split(trimmed, '\n');

	// while(matrix[i])
	// {
		validate_identifier(matrix[0], rt);
	// 	i++;
	// }
} //validar mais de uma quebra de linha

int	main(int argc, char **argv)
{
	t_rt	rt;

	input_validation(argc);
	rt.scene_name = ft_strdup(argv[1]);
	extension_validation(rt.scene_name);
	get_scene(&rt);
	validate_scene(&rt);
}

//lighting é inicializado com os valores passados por parametro
