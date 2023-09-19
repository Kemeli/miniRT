#include <minirt.h>

double	 verify_and_get_double(char *str) //refatorar
{
	if(str && is_double(str))
		return(ft_atof(str));
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
