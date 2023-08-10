#include <minirt.h>

int	get_num_len(char *str, int i)
{
	while(str[i] != ',')
		i++;
	return (i);
}

t_tuple	char_to_color(char *str)
{
	char	*r;
	char	*g;
	char	*b;
	t_tuple	rgb;
	int		i;

	i = get_num_len(str, 0);
	r = ft_substr(str, 0, i);
	g = ft_substr(str, i + 1, get_num_len(str, i + 1));
	i = get_num_len(str, i + 1);
	b = ft_substr(str, i + 1, ft_strlen(str));
	rgb = color(ft_atof(r) / 255, ft_atof(g) / 255, ft_atof(b) / 255);
	free(r);
	free(g);
	free(b);
	return (rgb);
}

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
