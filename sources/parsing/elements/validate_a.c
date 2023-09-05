#include <minirt.h>

t_tuple	validate_a(char *element, t_rt *rt)
{
	char	**sub;
	t_tuple	ambient;

	sub = ft_split(element, ' ');
	rt->a_ratio = is_btwen_range(sub[1], "0", "1");
	if (!rt->a_ratio)
	{
		error_msg("invalid A ratio");
		free_split(sub);
		return(NULL);
	}
	rt->a_color = validate_color(sub[2]);
	if(!rt->a_color)
	{
		error_msg("invalid A color");
		free_split(sub);
		return(NULL);
	}
	ambient = multiply_tuple_by_scalar(rt->a_color, rt->a_ratio);
	free_split(sub);
	return (ambient);
}
//tirar o rt daqui
