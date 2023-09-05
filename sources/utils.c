#include <minirt.h>

char	compare_doubles(double n1, double n2)
{
	double	epsilon;

	epsilon = 0.00001;
	if (fabs(n1 - n2) <= epsilon)
		return (TRUE);
	return (FALSE);
}

void	ft_swap(void *a, void *b)
{
	void	*tmp;

	tmp = a;
	a = b;
	b = tmp;
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		ft_free_ptr((void *) &split[i]);
		i++;
	}
	ft_free_ptr((void *) split);
}
