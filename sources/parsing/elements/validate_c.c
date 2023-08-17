#include <minirt.h>

static char	validate_c_element(char *str, char type, t_rt *rt)
{
	if (type == 'c')
	{
		rt->c_coordinates =  validate_coordinates(str);
		if (!rt->c_coordinates)
			return(error_msg("invalid C coordinates"));
	}
	else if (type == 'n')
	{
		rt->c_normal = validate_normal(str);
		if (!rt->c_normal)
			return(error_msg("invalid C normal"));
	}
	else if (type == 'a')
	{
		rt->c_fov = validate_angle(str);
		if (!rt->c_fov)
			return(error_msg("invalid C fov"));
	}
	free(str);
	return (1);
}

char	validate_c(char *element, t_rt *rt)
{
	int		i;
	int		j;
	char	*sub;

	i = 1;
	i = skip_spaces(i, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	if(!validate_c_element(sub, 'c', rt))
		return(0);
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	if(!validate_c_element(sub, 'n', rt))
		return(0);
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	if(!validate_c_element(sub, 'a', rt))
		return(0);
	// printf("c_coordinates: %f %f %f\n", rt->c_coordinates[0], rt->c_coordinates[1], rt->c_coordinates[2]);
	// printf("c_normal: %f %f %f\n", rt->c_normal[0], rt->c_normal[1], rt->c_normal[2]);
	// printf("c_fov: %f\n", rt->c_fov);
	rt->c = 1;
	return (1);
}
