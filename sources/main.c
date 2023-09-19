#include <minirt.h>

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

int	main(int argc, char **argv)
{
	t_rt	*rt;
	t_data	*data;

	rt = ft_calloc(1, sizeof(t_rt));
	input_validation(argc);
	extension_validation(argv[1]);
	data = ft_calloc(1, sizeof(t_data));
	data->w = create_world();
	if (!validate_scene(rt, argv[1], data))
	{
		free_scene(rt, data);
		free(data);
		return (0);
	}
	start_mlx(data);
	make_scene(data);
	free_scene(rt, data);
	set_mlx_hooks(data);
	mlx_loop(data->mlx_ptr);
}
//testar arquivo invalido e arquivo vazio
