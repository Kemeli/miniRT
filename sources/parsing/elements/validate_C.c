#include <minirt.h>

static void	validate_c_element(char *str, char type, t_rt *rt)
{
	if (type == 'c')
	{
		rt->C_coordinates =  validate_coordinates(str);
		if (!rt->C_coordinates)
			error_and_exit("invalid C coordinates");
	}
	else if (type == 'n')
	{
		rt->C_normal = validate_normal(str);
		if (!rt->C_normal)
			error_and_exit("invalid C normal");
	}
	else if (type == 'a')
	{
		rt->C_fov = validate_angle(str);
		if (!rt->C_fov)
			error_and_exit("invalid C fov");
	}
	free(str);
}

void	validate_c(char *element, t_rt *rt)
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
	// printf("C_coordinates: %f %f %f\n", rt->C_coordinates[0], rt->C_coordinates[1], rt->C_coordinates[2]);
	// printf("C_normal: %f %f %f\n", rt->C_normal[0], rt->C_normal[1], rt->C_normal[2]);
	// printf("C_fov: %f\n", rt->C_fov);
}
