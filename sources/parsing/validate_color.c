#include <minirt.h>

char	validate_color(char *color)
{
	int		i;
	int		comma;
	int		n;
	char	*str;
	int		j;

	i = 0;
	comma = 0;
	j = 0;
	while (color && color[i])
	{
		while (color && color[i] && ft_isdigit(color[i]) && color[i] != ',')
			i++;
		str = ft_substr(color, j, i);
		n = ft_atoi(str);
		free(str);
		if (color[i] == ',')
		{
			comma++;
			i++;
		}
		if ((comma != 2 && !ft_isdigit(color[i])) || n < 0 || n > 255)
			return (0);
		j = i;
	}
	return (1);
}
