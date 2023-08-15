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
