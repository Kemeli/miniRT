#include <minirt.h>

int		len_to_space(char *str);
double	ft_atof(const char *str);
char	*make_num(char *str);

double	is_btwen_range(char *ratio, char *r0, char *r1)
{
	double	num;
	char	*s_num;

	s_num = make_num(ratio);
	num = ft_atof(s_num);
	free(s_num);
	if (num >= ft_atof(r0) && num <= ft_atof(r1))
		return (num);
	return (-1);
}

char	*make_num(char *str)
{
	char	*s_num;

	if (str[0] == '-')
		s_num = ft_substr(str, 0, 4);
	else
		s_num = ft_substr(str, 0, 3);
	return (s_num);
}

int	len_to_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}
