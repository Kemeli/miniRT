#include <minirt.h>

t_tuple	validate_a(char *element, t_rt *rt)
{
	int		i;
	int		j;
	char	*sub;
	t_tuple	ambient;

	i = 1;
	i = skip_spaces(i, element);
	j = 3;
	sub = ft_substr(element, i, j);
	rt->a_ratio = is_btwen_range(sub, "0", "1");
	if (!rt->a_ratio)
	{
		error_msg("invalid A ratio");
		return(NULL);
	}
	free(sub);
	while (element[i + j] && element[i + j] == ' ')
		j++;
	rt->a_color = validate_color(element + (i + j));
	if(!rt->a_color)
	{
		error_msg("invalid A color");
		return(NULL);
	}
	ambient = multiply_tuple_by_scalar(rt->a_color, rt->a_ratio);
	return (ambient);
}
//tirar o rt daqui
