/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:25:09 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:25:10 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*get_scene(char *scene_name)
{
	int		fd;
	char	*buffer;
	char	*cpy_scene;
	char	*ret;

	fd = open(scene_name, O_RDONLY);
	if (fd < 0)
		return (error_msg_scene("couldn't open fd"));
	buffer = ft_calloc(1, sizeof(char));
	buffer = get_line(buffer, fd);
	cpy_scene = ft_strdup(buffer);
	free(buffer);
	if (cpy_scene[0] == '\0')
		return (clean_and_error_msg("scene is empty", cpy_scene));
	if (close(fd) == -1)
		return (clean_and_error_msg("couldn't close fd", cpy_scene));
	ret = ft_strtrim(cpy_scene, " \t\n\v\f\r");
	free(cpy_scene);
	return (ret);
}
