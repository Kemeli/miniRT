#include <minirt.h>

char	is_btwen_range(char *ratio, char *r0, char *r1)
{
	int		k;

	k = 0;
	if (r0[0] != '-' && ratio[k] == '-')
		return (0);
	if (r1[0] == '-')
		return (0);
	if (ratio[k] == '-')
		k++;
	if (!ft_isdigit(ratio[k])
		|| ratio[k + 1] != '.'
		|| !ft_isdigit(ratio[k + 2]))
		return (0);
	if (ratio[k] > r0[k] && ratio[k] != r1[0])
		return (0);
	if (ratio[k] == r1[0] && ratio[k + 2] > r1[2])
		return (0);
	return (1);
}
