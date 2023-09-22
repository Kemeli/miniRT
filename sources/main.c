#include <minirt.h>

void	input_validation(int argc)
{
	if (argc != 2)
	{
		printf ("ERROR\n");
		printf ("invalid number of arguments, it must be 2\n");
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
		printf ("invalid scene extension, it must be .rt\n");
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	input_validation(argc);
	extension_validation(argv[1]);
	data = ft_calloc(1, sizeof(t_data));
	data->w = create_world();
	if (!validate_scene(argv[1], data))
	{
		free_scene(data);
		free(data);
		return (0);
	}
	start_mlx(data);
	make_scene(data);
	free_scene(data);
	set_mlx_hooks(data);
	mlx_loop(data->mlx_ptr);
}
//testar arquivo invalido e arquivo vazio
