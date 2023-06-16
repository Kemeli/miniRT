/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:30:26 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/01/19 17:47:43 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*save_next_line(char *str)
{
	char	*next_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str || !str[i])
	{
		free(str);
		return (NULL);
	}
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	next_line = malloc((sizeof(char) * ft_strlen(str) - i + 1));
	if (!next_line)
		return (NULL);
	while (str[i])
		next_line[j++] = str[i++];
	next_line[j] = '\0';
	free(str);
	return (next_line);
}

static char	*get_line(char *str)
{
	int		i;
	char	*line;
	int		len;

	i = 0;
	len = 0;
	if (!str || !str[i])
		return (NULL);
	while (str[len] != '\n' && str[len])
		len++;
	if (str[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*read_file(char *hold, int fd)
{
	int		bytes_r;
	char	*temp;
	char	*aux;

	bytes_r = 1;
	aux = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!aux)
		return (NULL);
	while (!ft_strchr(hold, '\n') && bytes_r > 0)
	{
		bytes_r = read (fd, aux, BUFFER_SIZE);
		if (bytes_r == -1)
		{
			free(aux);
			free(hold);
			return (NULL);
		}
		aux[bytes_r] = '\0';
		temp = ft_strjoin(hold, aux);
		free(hold);
		hold = temp;
	}
	free(aux);
	return (hold);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*line;
	char		*hold;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	if (!next_line)
		next_line = ft_strdup("");
	hold = read_file(next_line, fd);
	line = get_line(hold);
	next_line = save_next_line(hold);
	return (line);
}
