#include <minirt.h>

t_tuple	validate_coordinates(char *str)
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
	return (point(n[0], n[1], n[2]));
}
