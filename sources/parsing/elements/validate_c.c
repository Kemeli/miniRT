#include <minirt.h>

static void	validate_c_element(char *str, char type, t_rt *rt)
{
	if (type == 'c')
	{
		rt->c_coordinates =  validate_coordinates(str);
		if (!rt->c_coordinates)
			error_and_exit("invalid C coordinates");
	}
	else if (type == 'n')
	{
		rt->c_normal = validate_normal(str);
		if (!rt->c_normal)
			error_and_exit("invalid C normal");
	}
	else if (type == 'a')
	{
		rt->c_fov = validate_angle(str);
		if (!rt->c_fov)
			error_and_exit("invalid C fov");
	}
	free(str);
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
	validate_c_element(sub, 'c', rt);
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	validate_c_element(sub, 'n', rt);
	i = skip_spaces(j, element);
	j = go_through_char(i, element);
	sub = ft_substr(element, i, j - i);
	validate_c_element(sub, 'a', rt);
	// printf("c_coordinates: %f %f %f\n", rt->c_coordinates[0], rt->c_coordinates[1], rt->c_coordinates[2]);
	// printf("c_normal: %f %f %f\n", rt->c_normal[0], rt->c_normal[1], rt->c_normal[2]);
	// printf("c_fov: %f\n", rt->c_fov);
	return (1);
}
