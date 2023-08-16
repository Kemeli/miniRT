#include <minirt.h>

float	 verify_and_get_float(char *str) //refatorar
{
	if(str && is_float(str))
		return(ft_atof(str));
	return (0);
}

void	validate_sp(char *line, t_rt *rt)
{
	char	*str;
	int		i;
	int		j;
	char	*sub;

	str = ft_strtrim(line, " \t\n\v\f\r");
	i = 2;
	i = skip_spaces(i, str);
	j = go_through_char(i, str);
	sub = ft_substr(str, i, j - i);
	printf("\nsub: %s\n", sub);
	rt->sp_coordinates = validate_coordinates(sub);
	printf("sp_coordinates: %f %f %f\n", rt->sp_coordinates[0], rt->sp_coordinates[1], rt->sp_coordinates[2]);
	free(sub);
	if(!rt->sp_coordinates)
		return(error_and_exit("invalid sp coordinates"));

	i = skip_spaces(j, str);
	j = go_through_char(i, str);
	sub = ft_substr(str, i, j - i);
	rt->sp_diameter = verify_and_get_float(sub);
	free(sub);
	printf("sp_diameter: %f\n", rt->sp_diameter);
	if(!rt->sp_diameter)
		return(error_and_exit("invalid sp diameter"));

	i = skip_spaces(j, str);
	j = go_through_char(i, str);
	sub = ft_substr(str, i, j - i);
	rt->sp_color = validate_color(sub);
	free(sub);
	printf("sp_color: %f %f %f\n", rt->sp_color[0], rt->sp_color[1], rt->sp_color[2]);
	if(!rt->sp_color)
		return(error_and_exit("invalid sp color"));
	free(str);
}

// (gdb) p index
// $7 = 18
// (gdb) p str[index]
// $8 = 0 '\000'
// (gdb) p str
// $9 = 0x40c530 "sp 0,0,20 20 255,0"
