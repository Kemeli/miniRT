#include <minirt.h>

double *validate_tuple(char *str, double *n)
{
	int		i;
	int		pos;
	char	**num;

	pos = 0;
	i = 0;
	num = ft_split(str, ',');
	while (num && num[i])
	{
		if(is_double(num[i]))
			n[pos++] = ft_atof(num[i]);
		else
		{
			free_split(num);
			return (NULL);
		}
		i++;
	}
	free_split(num);
	return (n);
}

t_tuple	validate_coordinates(char *str)
{
	double	n[3];

	if (!validate_tuple(str, n))
		return (NULL);
	return (point(n[0], n[1], n[2]));
}
