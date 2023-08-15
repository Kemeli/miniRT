#include <minirt.h>

void	error_and_exit(char *error_message)
{
	printf ("ERROR\n");
	printf ("%s\n", error_message);
	exit (0);
}

t_tuple	validate_tuple(char *str, float *n)
{
	int		i;
	int		j;
	int		pos;
	int		comma;

	i = 0;
	j = 0;
	pos = 0;
	comma = 0;
	while (str && str[i])
	{
		if (str && str[i] && str[i] == '-')
			i++;
		i = go_through_num(str, i);
		n[pos++] = get_float(str, i, j);
		comma = count_comma(str, &i, comma);
		if (((comma != 2 && !ft_isdigit(str[i]))))
			return (NULL);
		j = i;
	}
	return(n);
}