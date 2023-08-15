#include <minirt.h>

static int	get_number(char *color, int i, int j)
{
	char	*str;
	int		num;

	str = ft_substr(color, j, i);
	num = ft_atoi(str);
	free(str);
	return (num);
}

t_tuple	validate_color(char *str)
{
	int		i;
	int		j;
	int		pos;
	int		comma;
	int		n[3];

	i = 0;
	j = 0;
	comma = 0;
	pos = 0;
	while (str && str[i])
	{
		while (str && str[i] && ft_isdigit(str[i]) && str[i] != ',')
			i++;
		n[pos] = get_number(str, i, j);
		if (n[pos] < 0 || n[pos] > 255)
			return (NULL);
		pos++;
		comma = count_comma(str, &i, comma);
		if (comma != 2 && !ft_isdigit(str[i]))
			return (NULL);
		j = i;
	}
	return (color(n[0] / 255.0, n[1] / 255.0, n[2] / 255.0));
}
