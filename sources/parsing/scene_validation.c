/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:25:20 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:25:20 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static char	is_object(char *element, t_world *w)
{
	if (element[0] == 's' && element[1] == 'p' && element[2] == ' ')
		return (validate_sp(element, w));
	else if (element[0] == 'p' && element[1] == 'l' && element[2] == ' ')
		return (validate_pl(element, w));
	else if (element[0] == 'c' && element[1] == 'y' && element[2] == ' ')
		return (validate_cy(element, w));
	return (error_msg("invalid element", "contain only A, C, L, sp, pl, cy"));
}

static char	validate_identifier(char *element, t_data *data)
{
	char	ret;

	ret = 0;
	if (element[0] == 'A' && element[1] == ' ')
		ret = validate_a(element, data->w);
	else if (element[0] == 'C' && element[1] == ' ')
		ret = validate_c(element, &data->c);
	else if (element[0] == 'L' && element[1] == ' ')
		ret = validate_l(element, &data->w->light);
	else
		ret = is_object(element, data->w);
	return (ret);
}

static char	**get_elements(char *scene_name)
{
	char	**elements;
	char	*scene;

	scene = get_scene(scene_name);
	if (!scene)
		return (0);
	elements = ft_split(scene, '\n');
	free(scene);
	if (!elements)
		return (error_msg_scene("empty scene"));
	if (!check_mandatory_elements(elements) || !check_text_format(elements))
	{
		free_split(elements);
		return (NULL);
	}
	return (elements);
}

char	validate_scene(char *scene_name, t_data *data)
{
	char	**elements;
	char	ret;
	int		i;

	elements = get_elements(scene_name);
	if (!elements)
		return (0);
	ret = 0;
	i = -1;
	while (elements[++i])
	{
		ret = validate_identifier(elements[i], data);
		if (!ret)
			break ;
	}
	free_split(elements);
	return (ret);
}
