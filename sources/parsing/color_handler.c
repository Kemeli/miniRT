#include <minirt.h>

static void	*clear_and_return(char **str)
{
	free_split(str);
	return (NULL);
}

static char	is_valid_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_tuple	validate_color(char *str)
{
	int		i;
	int		pos;
	int		n[3];
	char	**nums;

	i = 0;
	pos = 0;
	nums = ft_split(str, ',');
	while (nums[i])
	{
		if(!is_valid_num(nums[i]))
			return(clear_and_return(nums));
		n[pos] = ft_atoi(nums[i]);
		if (n[pos] < 0 || n[pos] > 255)
			return(clear_and_return(nums));
		pos++;
		i++;
	}
	free_split(nums);
	return (color(n[0] / 255.0, n[1] / 255.0, n[2] / 255.0));
}
