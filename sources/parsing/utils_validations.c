#include <minirt.h>

double	 verify_and_get_double(char *str) //refatorar
{
	double	range;

	if(str && is_double(str))
	{
		range = ft_atof(str);
		if (range > 0 && range < MAX_RANGE)
			return(range);
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

char	check_text_format(char **elements)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(elements[i])
	{
		j = 0;
		while(elements[i][j])
		{
			if (elements[i][j] == '\t')
				return (error_msg("text format (tab)", "be spaces"));
			j++;
		}
		i++;
	}
	return (1);
}

char	check_mandatory_elements(char **elements)
{
	int		acl[3];
	int		i;

	i = -1;
	acl[0] = 0;
	acl[1] = 0;
	acl[2] = 0;
	while (elements[++i])
	{
		if (elements[i][0] == 'A' && !acl[0])
			acl[0] = 1;
		else if (elements[i][0] == 'A' && acl[0])
			return (error_msg("repeated ambient light", "contain only one"));
		else if (elements[i][0] == 'C' && !acl[1])
			acl[1] = 1;
		else if (elements[i][0] == 'C' && acl[1])
			return (error_msg("repeated camera", "contain only one"));
		else if (elements[i][0] == 'L' && !acl[2])
			acl[2] = 1;
		else if (elements[i][0] == 'L' && acl[2])
			return (error_msg("repeated light", "contain only one"));
	}
	if (!acl[0] || !acl[1] || !acl[2])
		return (error_msg("missing mandatory element", "contain A, C and L"));
	return (1);
}
