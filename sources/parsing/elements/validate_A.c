#include <minirt.h>

void	validate_a(char *element, t_rt *rt)
{
	int		i;
	int		j;
	char	*sub;

	i = 1;
	i = skip_spaces(i, element);
	j = 3;
	sub = ft_substr(element, i, j);
	rt->A_ratio = is_btwen_range(sub, "0", "1");
	if (!rt->A_ratio)
		error_and_exit("invalid A ratio");
	free(sub);
	while (element[i + j] && element[i + j] == ' ')
		j++;
	rt->A_color = validate_color(element + (i + j));
	if(!rt->A_color)
		error_and_exit("invalid A color");
	// printf("A_color: %f %f %f\n", rt->A_color[0], rt->A_color[1], rt->A_color[2]);
	// printf("A_ratio: %f\n", rt->A_ratio);
}
