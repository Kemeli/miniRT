#include <minirt.h>

char	is_double(char *str)
{
	if (*str == '-')
		str++;
	if (!ft_isdigit(*str) || (ft_strchr(str, '.') != ft_strrchr(str, '.')))
		return (0);
	while (*str)
	{
		if (*str == '.')
			str++;
		if (!ft_isdigit(*str) && !ft_strrchr(".\0", *str))
			return (0);
		str++;
	}
	return (1);
}
