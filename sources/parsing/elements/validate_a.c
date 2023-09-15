#include <minirt.h>

t_tuple	validate_a(char *element)
{
	char	**sub;
	t_tuple	ambient;
	double	ratio;
	t_tuple	color;

	sub = ft_split(element, ' ');
	if (count_infos(sub) != 2)
	{
		error_msg("invalid amount of ambient infos");
		free_split(sub);
		return(NULL);
	}
	ratio = is_btwen_range(sub[1], "0", "1");
	if (!ratio)
	{
		error_msg("invalid A ratio");
		free_split(sub);
		return(NULL);
	}
	color = validate_color(sub[2]);
	if(!color)
	{
		error_msg("invalid A color");
		free_split(sub);
		return(NULL);
	}
	ambient = multiply_tuple_by_scalar(color, ratio);
	free(color);
	free_split(sub);
	return (ambient);
}
//tirar o rt daqui
