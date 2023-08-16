#include <minirt.h>

static void	get_scene(t_rt *rt)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(rt->scene, O_RDONLY);
	if (fd < 0)
		error_and_exit("invalid scene file");
	while (get_next_line(fd, &line) > 0)
	{
		temp = ft_strjoin(rt->cpy_scene, line);
		free(rt->cpy_scene);
		rt->cpy_scene = ft_strjoin(temp, "\n");
		free(temp);
		free(line);
	}
	temp = ft_strjoin(rt->cpy_scene, line);
	free(rt->cpy_scene);
	rt->cpy_scene = ft_strjoin(temp, "\n");
	free(temp);
	free(line);
	close(fd);
}

static void	validate_identifier(char *line, t_rt *rt)
{
	if (line && line[0] && line[1] && line[2])
	{
		if (line[0] == 'A' && line[1] == ' ')
			validate_A(line, rt);
		else if (line[0] == 'C' && line[1] == ' ') //dar trim em todos os line antes dessa verificação
			validate_C(line, rt);
		else if (line[0] == 'L' && line[1] == ' ')
			validate_L(line, rt);
		else if (line[0] == 's' && line[1] == 'p' && line[2] == ' ')
			validate_sp(line, rt);
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
	get_scene(rt);
	trimmed = ft_strtrim(rt->cpy_scene, " \t\n\v\f\r");
	matrix = ft_split(trimmed, '\n');
	free(trimmed);
	// while(matrix[i])
	// {
		validate_identifier(matrix[0], rt);
		validate_identifier(matrix[1], rt);
		validate_identifier(matrix[2], rt);
		validate_identifier(matrix[3], rt);
	// 	i++;
	// }
	free_split(matrix);
} //validar mais de uma quebra de linha
//validar só um elemento de cada
