#include <minirt.h>

char	is_float(char *str)
{
	if (*str != '-')
		str++;
	while (*str)
	{
		if (*str == '.')
		{
			str++;
			break ;
		}
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static float	get_number(char *str, int i, int j)
{
	char	*ptr;
	float	num;

	ptr = ft_substr(str, j, i);
	num = ft_atof(ptr);
	free(ptr);
	return (num);
}

t_tuple	validate_coordenates(char *str)
{
	int		i;
	int		j;
	int		k;
	float	n[3];
	int		comma;

	i = 0;
	j = 0;
	k = 0;
	comma = 0;
	while (str && str[i])
	{
		while (str && str[i] && ft_isdigit(str[i]) && str[i] != ',')
			i++;
		n[k] = get_number(str, i, j);
		k++;
		if (!is_float)
			return (0);
		if (str[i] == ',')
		{
			comma++;
			i++;
		}
		if ((comma != 2 && !ft_isdigit(str[i])))
			return (NULL);
		j = i;
	}
	return (point(n[0], n[1], n[2]));
}