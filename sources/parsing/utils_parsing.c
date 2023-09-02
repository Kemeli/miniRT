#include <minirt.h>

void	count_comma(int *index, int *comma)
{
	(*comma)++;
	(*index)++;
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

double	get_double(char *str, int i, int j)
{
	char	*ptr;
	double	num;

	ptr = ft_substr(str, j, i);
	num = ft_atof(ptr);
	free(ptr);
	return (num);
}

int	go_through_char(int index, char *str)
{
	while(str[index] != '\0' && str[index] != ' ')
		index++;
	return (index);
}

int	skip_spaces(int index, char *str)
{
	while(str[index] && str[index] == ' ')
		index++;
	return (index);
}
