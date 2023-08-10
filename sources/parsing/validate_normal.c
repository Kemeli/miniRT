#include <minirt.h>

static float	get_float(char *str, int i, int j)
{
	char	*ptr;
	float	num;

	ptr = ft_substr(str, j, i);
	num = ft_atof(ptr);
	free(ptr);
	return (num);
}

static int	go_through_num(char *str, int i)
{
	while (str && str[i] && ft_isdigit(str[i]) && str[i] != ',')
		i++;
	if (str[i] == '.')
		i++;
	while (str && str[i] && ft_isdigit(str[i]) && str[i] != ',')
		i++;
	return (i);
}

static int	count_comma(char *str, int *i, int comma)
{
	if (str[(*i)] == ',')
	{
		(*i)++;
		return (comma + 1);
	}
	return (comma);
}

static char	validate_range(float *n)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (fabs(n[i]) > 1.0f && fabs(n[0]) - 1.0f > EPSILON)
			return (0);
		i++;
	}
	return (1);
}

t_tuple	validate_normal(char *str)
{
	int		i;
	int		j;
	int		pos;
	int		comma;
	float	n[3];

	i = 0;
	j = 0;
	pos = 0;
	comma = 0;
	while (str && str[i])
	{
		if (str && str[i] && str[i] == '-')
			i++;
		i = go_through_num(str, i);
		n[pos++] = get_float(str, i, j);
		comma = count_comma(str, &i, comma);
		if ((comma != 2 && !ft_isdigit(str[i])))
			return (NULL);
		j = i;
	}
	if (validate_range(n))
		return (vector(n[0], n[1], n[2]));
	return (NULL);
}
