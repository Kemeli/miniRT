#include <minirt.h>

double	 verify_and_get_double(char *str) //refatorar
{
	double	positive;

	if(str && is_double(str))
	{
		positive = ft_atof(str);
		if (positive > 0)
			return(positive);
	}
	return (0);
}

int	count_infos(char **infos)
{
	int	i;

	i = 0;
	while (infos[i])
		i++;
	return (i - 1);
}

char	check_repeated_elements(char **elements)
{
	char	a;
	char	c;
	char	l;
	int		i;

	a = 0;
	c = 0;
	l = 0;
	i = -1;
	while (elements[++i])
	{
		if (elements[i][0] == 'A' && !a)
			a = 1;
		else if (elements[i][0] == 'A' && a)
			return (error_msg("repeated ambient light"));
		else if (elements[i][0] == 'C' && !c)
			c = 1;
		else if (elements[i][0] == 'C' && c)
			return (error_msg("repeated camera"));
		else if (elements[i][0] == 'L' && !l)
			l = 1;
		else if (elements[i][0] == 'L' && l)
			return (error_msg("repeated light"));
	}
	return (1);
}
