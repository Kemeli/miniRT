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

static char	get_scene(t_rt *rt)
{
	int		fd;
	char	*buffer;

	fd = open(rt->scene_name, O_RDONLY);
	if (fd < 0)
		return(error_msg("couldn't open fd"));
	buffer = ft_calloc(1, sizeof(char));
	buffer = get_line(buffer, fd);
	rt->cpy_scene = ft_strdup(buffer);
	free(buffer);
	if(rt->cpy_scene[0] == '\0')
		return(error_msg("scene is empty"));
	if (close(fd) == -1)
		return(error_msg("couldn't close fd"));
	return(1);
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

static char	validate_identifier(char *line, t_rt *rt, t_world *w)
{
	char	*element;
	char	ret;

	ret = 0;
	element = ft_strtrim(line, " \t\n\v\f\r");
	if (element && element[0] && element[1] && element[2]) //talvez n precise desse if
	{
		if (element[0] == 'A' && element[1] == ' ' && !rt->a)
			ret = validate_a(element, rt);
		else if (element[0] == 'C' && element[1] == ' ' && !rt->c)
			ret = validate_c(element, rt);
		else if (element[0] == 'L' && element[1] == ' ' && !rt->l)
			ret = validate_l(element, rt);
		else
			ret = is_object(element, rt, w);
	}
	free(element);
	return (ret);
}

char	validate_scene(t_rt *rt, t_world *w)
{
	char		*trimmed;
	char		**splitted_scene;
	int			i;
	char		ret;

	ret = 1;
	i = 0;
	get_scene(rt);
	trimmed = ft_strtrim(rt->cpy_scene, " \t\n\v\f\r");
	splitted_scene = ft_split(trimmed, '\n');
	free(trimmed);
	while(splitted_scene[i])
	{
		ret = validate_identifier(splitted_scene[i], rt, w);
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

