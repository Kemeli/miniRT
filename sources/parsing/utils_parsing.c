#include <minirt.h>

int	count_comma(char *str, int *i, int comma)
{
	if (str[(*i)] == ',')
	{
		(*i)++;
		return (comma + 1);
	}
	return (comma);
}

int	go_through_num(char *str, int i)
{
	while (str && str[i] && ft_isdigit(str[i]) && str[i] != ',')
		i++;
	if (str[i] == '.')
		i++;
	while (str && str[i] && ft_isdigit(str[i]) && str[i] != ',')
		i++;
	return (i);
}

float	get_float(char *str, int i, int j)
{
	char	*ptr;
	float	num;

	ptr = ft_substr(str, j, i);
	num = ft_atof(ptr);
	free(ptr);
	return (num);
}
