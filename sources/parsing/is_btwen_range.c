#include <minirt.h>

int	len_to_space(char *str);

char	is_btwen_range(char *ratio, char *r0, char *r1)
{
	int		k;

	k = 0;
	if ((r0[0] != '-' && ratio[k] == '-') || r1[0] == '-')
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
	return (1);
}

int	len_to_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}
