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

static char	*get_scene(char *scene_name)
{
	int		fd;
	char	*buffer;
	char	*cpy_scene;
	char	*ret;

	fd = open(scene_name, O_RDONLY);
	if (fd < 0)
		return(error_msg_scene("couldn't open fd"));
	buffer = ft_calloc(1, sizeof(char));
	buffer = get_line(buffer, fd);
	cpy_scene = ft_strdup(buffer);
	free(buffer);
	if(cpy_scene[0] == '\0')
		return(error_msg_scene("scene is empty"));
	if (close(fd) == -1)
		return(error_msg_scene("couldn't close fd"));
	ret = ft_strtrim(cpy_scene, " \t\n\v\f\r");
	free(cpy_scene);
	return(ret);
}

static char	is_object(char *element, t_rt *rt, t_world *w)
{
	if (element[0] == 's' && element[1] == 'p' && element[2] == ' ')
		return(validate_sp(element, rt, w));
	else if (element[0] == 'p' && element[1] == 'l' && element[2] == ' ')
		return(validate_pl(element, rt, w));
	else if (element[0] == 'c' && element[1] == 'y' && element[2] == ' ')
		return(validate_cy(element, rt, w));
	return (error_msg("invalid element"));
}

static char	validate_identifier(char *element, t_rt *rt, t_data *data)
{
	char	ret;

	ret = 0;
	if (element[0] == 'A' && element[1] == ' ' && !data->w->ambient)
		ret = validate_a(element, data->w);
	else if (element[0] == 'C' && element[1] == ' ' && !data->c)
		ret = validate_c(element, rt, &data->c);
	else if (element[0] == 'L' && element[1] == ' ' && !data->w->light)
		ret = validate_l(element, rt, &data->w->light);
	else
		ret = is_object(element, rt, data->w);
	return (ret);
}

char	validate_scene(t_rt *rt, char *scene_name, t_data *data)
{
	char	**elements;
	int		i;
	char	ret;
	char	*scene;

	scene = get_scene(scene_name);
	if (!scene)
		return (0);
	elements = ft_split(scene, '\n');
	free(scene);
	ret = 0;
	i = 0;
	while(elements[i]) //se der problema aqui é por causa do \r
	{
		ret = validate_identifier(elements[i], rt, data);
		if (!ret)
			break;
		i++;
	}
	free_split(elements);
	return(ret);
}
