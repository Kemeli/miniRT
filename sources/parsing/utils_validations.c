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
				return (error_msg("invalid text format (tab)"));
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
			return (error_msg("repeated ambient light"));
		else if (elements[i][0] == 'C' && !acl[1])
			acl[1] = 1;
		else if (elements[i][0] == 'C' && acl[1])
			return (error_msg("repeated camera"));
		else if (elements[i][0] == 'L' && !acl[2])
			acl[2] = 1;
		else if (elements[i][0] == 'L' && acl[2])
			return (error_msg("repeated light"));
	}
	if (!acl[0] || !acl[1] || !acl[2])
		return (error_msg("missing mandatory element (A, C or L)"));
	return (1);
}
