#include <minirt.h>

float	validate_angle(char *angle)
{
	int		i;
	char	*s_angle;
	float	f_angle;

	i = 0;
	if (angle[0] == '-' || ft_strchr(angle, ','))
		return (-1);
	while (ft_isdigit(angle[i]))
		i++;
	if (angle[i] == '.')
		i++;
	while (ft_isdigit(angle[i]))
		i++;
	s_angle = ft_substr(angle, 0, i);
	f_angle = ft_atof(s_angle);
	free(s_angle);
	if (f_angle < 0 || f_angle > 180)
		return (-1);
	return (f_angle);
}