#include <minirt.h>

char	validate_a(char *element, t_rt *rt)
{
	int		i;
	int		j;
	char	*sub;

	i = 1;
	i = skip_spaces(i, element);
	j = 3;
	sub = ft_substr(element, i, j);
	rt->a_ratio = is_btwen_range(sub, "0", "1");
	if (!rt->a_ratio)
		return(error_msg("invalid A ratio"));
	free(sub);
	while (element[i + j] && element[i + j] == ' ')
		j++;
	rt->a_color = validate_color(element + (i + j));
	// printf("a_color: %f %f %f\n", rt->a_color[0], rt->a_color[1], rt->a_color[2]);
	if(!rt->a_color)
		return(error_msg("invalid A color"));
	// printf("a_ratio: %f\n", rt->a_ratio);
	rt->a = 1;
	return (1);
}