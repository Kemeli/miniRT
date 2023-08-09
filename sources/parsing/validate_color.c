#include <minirt.h>

char	validate_color(char *color)
{
	int		i;
	int		comma;
	int		num;
	char	*str;
	int		j;

	i = 0;
	comma = 0;
	while (color && color[i])
	{
		while (color && color[i] && ft_isdigit(color[i]) && color[i] != ',')
			i++;
		str = ft_substr(color, j, i);
		num = ft_atoi(str);
		if (color[i] == ',')
		{
			comma++;
			i++;
		}
		if (comma > 2 || num < 0 || num > 255)
			return (0);
		j = i;
	}
	return (1);
}
