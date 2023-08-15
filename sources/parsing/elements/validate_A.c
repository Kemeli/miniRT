#include <minirt.h>

void	validate_A(char *A_line, t_rt *rt)
{
	int		i;
	int		j;
	char	*sub;
	char	*str;

	str = ft_strtrim(A_line, " \t\n\v\f\r");
	i = 1;
	i = skip_spaces(i, str);
	j = 3;
	sub = ft_substr(str, i, j);
	rt->A_ratio = is_btwen_range(sub, "0", "1");
	if (!rt->A_ratio)
		error_and_exit("invalid A ratio");
	free(sub);
	while (str[i + j] && str[i + j] == ' ')
		j++;
	rt->A_color = validate_color(str + (i + j));
	if(!rt->A_color)
		error_and_exit("invalid A color");
	// printf("A_color: %f %f %f\n", rt->A_color[0], rt->A_color[1], rt->A_color[2]);
	// printf("A_ratio: %f\n", rt->A_ratio);
	free(str);
}
