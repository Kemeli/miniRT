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

char	*validate_color(char *color)
{
	int		i;
	int		j;
	int		comma;
	int		n;

	i = 0;
	j = 0;
	comma = 0;
	while (color && color[i])
	{
		while (color && color[i] && ft_isdigit(color[i]) && color[i] != ',')
			i++;
		n = get_number(color, i, j);
		if (color[i] == ',')
		{
			comma++;
			i++;
		}
		if ((comma != 2 && !ft_isdigit(color[i])) || n < 0 || n > 255)
			return (NULL);
		j = i;
	}
	return (color);
}
