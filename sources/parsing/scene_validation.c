#include <minirt.h>

static char	*get_line(char *buffer, int fd)
{
	char	*temp;
	char	*line;

	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			temp = ft_strjoin(buffer, line);
			free(buffer);
			buffer = ft_strjoin(temp, "\n");
			free(temp);
			free(line);
		}
	}
	return (buffer);
}

static void	get_scene(t_rt *rt)
{
	int		fd;
	char	*buffer;

	fd = open(rt->scene_name, O_RDONLY);
	if (fd < 0)
		error_and_exit("couldn't open fd");
	buffer = ft_calloc(1, sizeof(char));
	buffer = get_line(buffer, fd);
	rt->cpy_scene = ft_strdup(buffer);
	if(rt->cpy_scene[0] == '\0')
		error_and_exit("scene is empty");
	if (close(fd) == -1)
		error_and_exit("couldn't close fd");
}

static void	validate_identifier(char *line, t_rt *rt)
{
	char	*element;

	element = ft_strtrim(line, " \t\n\v\f\r");
	if (element && element[0] && element[1] && element[2])
	{
		if (element[0] == 'A' && element[1] == ' ')
			validate_a(element, rt);
		else if (element[0] == 'C' && element[1] == ' ') //dar trim em todos os element antes dessa verificação
			validate_c(element, rt);
		else if (element[0] == 'L' && element[1] == ' ')
			validate_l(element, rt);
		else if (element[0] == 's' && element[1] == 'p' && element[2] == ' ')
			validate_sp(element, rt);
		else if (element[0] == 'p' && element[1] == 'l' && element[2] == ' ')
			validate_pl(element, rt);
		// else if (element[i] == 'cy' && element[1] == 'y' && element[2] == ' ')
		// 	return (cy);
	}
	free(element);
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
		validate_identifier(matrix[4], rt);
	// 	i++;
	// }
	free_split(matrix);
} //validar mais de uma quebra de linha
//validar só um elemento de cada
