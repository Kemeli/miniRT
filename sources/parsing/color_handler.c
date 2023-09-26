#include <minirt.h>

static void	*clear_and_return(char **str)
{
	free_split(str);
	return (NULL);
}

static char	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_tuple	validate_color(char *str)
{
	int		i;
	int		pos;
	int		num[3];
	char	**rgb;

	i = 0;
	pos = 0;
	rgb = ft_split(str, ',');
	while (rgb[i])
	{
		if(!is_num(rgb[i]))
			return(clear_and_return(rgb));
		num[pos] = ft_atoi(rgb[i]);
		if (num[pos] < 0 || num[pos] > 255)
			return(clear_and_return(rgb));
		pos++;
		i++;
	}
	free_split(rgb);
	if (pos != 3)
		return (NULL);
	return (color(num[0] / 255.0, num[1] / 255.0, num[2] / 255.0));
}
