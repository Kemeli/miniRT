#include <minirt.h>

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

static char	check_mandatory_elements(t_data *data)
{
	if (!data->w->ambient)
		return(error_msg("missing ambient light"));
	if (!data->c)
		return(error_msg("missing camera"));
	if (!data->w->light)
		return(error_msg("missing light"));
	return (1);
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
		return (error_msg_scene("empty scene"));//se é null não tem nada pra dar free
	if (!check_repeated_elements(elements))
	{
		free_split(elements);
		return (NULL);
	}
	return (elements);
}

char	validate_scene(t_rt *rt, char *scene_name, t_data *data)
{
	char	**elements;
	char	ret;
	int		i;

	elements = get_elements(scene_name);
	if (!elements)
		return (0);
	ret = 0;
	i = -1;
	while(elements[++i])
	{
		ret = validate_identifier(elements[i], rt, data);
		if (!ret)
			break;
	}
	if (ret && !check_mandatory_elements(data))
		ret = 0;
	free_split(elements);
	return(ret);
}
