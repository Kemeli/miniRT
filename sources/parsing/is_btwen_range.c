#include <minirt.h>

int		len_to_space(char *str);
float	ft_atof(const char *str);
char	*make_num(char *str);

float	is_btwen_range(char *ratio, char *r0, char *r1)
{
	int		k;
	char	*s_num;
	float	num;

	k = 0;
	if ((r0[0] != '-' && ratio[k] == '-') || r1[0] == '-')
		return (0);
	if ((ratio[k] == '-' && len_to_space(ratio) > 4)
		|| (ratio[k] != '-' && len_to_space(ratio) > 3))
		return (0);
	if (ratio[k] == '-')
		k++;
	if (!ft_isdigit(ratio[k])
		|| ratio[k + 1] != '.'
		|| !ft_isdigit(ratio[k + 2])
		|| len_to_space(ratio) > 4)
		return (0);
	if (ratio[k] > r0[k] && ratio[k] != r1[0])
		return (0);
	if (ratio[k] == r1[0] && ratio[k + 2] > r1[2])
		return (0);
	s_num = make_num(ratio);
	num = ft_atof(s_num);
	free(s_num);
	return (num);
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
