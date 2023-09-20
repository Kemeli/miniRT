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
