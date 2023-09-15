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

	fd = open(scene_name, O_RDONLY);
	if (fd < 0)
		return(error_msg_ptr("couldn't open fd"));
	buffer = ft_calloc(1, sizeof(char));
	buffer = get_line(buffer, fd);
	cpy_scene = ft_strdup(buffer);
	free(buffer);
	if(cpy_scene[0] == '\0')
		return(error_msg_ptr("scene is empty"));
	if (close(fd) == -1)
		return(error_msg_ptr("couldn't close fd"));
	return(cpy_scene);
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

static char	validate_identifier(char *line, t_rt *rt, t_data *data)
{
	char	*element;
	char	ret;

	ret = 0;
	element = ft_strtrim(line, " \t\n\v\f\r");
	if (element && element[0] && element[1] && element[2]) //talvez n precise desse if
	{
		if (element[0] == 'A' && element[1] == ' ' && !data->w->ambient)
		{
			data->w->ambient = validate_a(element);
			if (!data->w->ambient)
				ret = 0;
			else
				ret = 1;
		}
		else if (element[0] == 'C' && element[1] == ' ' && !data->c)
		{
			data->c = validate_c(element, rt);
			if (!data->c)
				ret = 0;
			else
				ret = 1;
		}
		else if (element[0] == 'L' && element[1] == ' ' && !data->w->light)
		{
			data->w->light = validate_l(element, rt);
			if (!data->w->light)
				ret = 0;
			else
				ret = 1;
		}
		else
			ret = is_object(element, rt, data->w);
	}
	free(element);
	return (ret);
}

char	validate_scene(t_rt *rt, char *scene_name, t_data *data)
{
	char		*trimmed;
	char		**splitted_scene;
	int			i;
	char		ret;
	char		*scene;

	ret = 1;
	i = 0;
	scene = get_scene(scene_name);
	trimmed = ft_strtrim(scene, " \t\n\v\f\r");
	free(scene);
	splitted_scene = ft_split(trimmed, '\n');
	free(trimmed);
	while(splitted_scene[i])
	{
		if (splitted_scene[i][0] == '\r')
		{
			i++;
			continue;
		}
		if (splitted_scene[i][0] == '\r') //gamb, como resolver?
			i++;
		ret = validate_identifier(splitted_scene[i], rt, data);
		if (!ret)
		{
			free_split(splitted_scene);
			return (0);
		}
		i++;
	}
	free_split(splitted_scene);
	return(1);
}
