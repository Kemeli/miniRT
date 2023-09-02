#include <minirt.h>

char	error_msg(char *error_message)
{
	printf ("ERROR\n");
	printf ("%s\n", error_message);
	return (0);
}

double *validate_tuple(char *str, double *n)
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
		n[pos++] = get_double(str, i, j);
		if (str[i] == ',')
			count_comma(&i, &comma);
		if (((comma != 2 && !ft_isdigit(str[i]))))
			return (NULL);
		j = i;
	}
	return (n);
}

double	 verify_and_get_double(char *str) //refatorar
{
	if(str && is_double(str))
		return(ft_atof(str));
	return (0);
}

void	add_object(t_world *w, t_object *obj)
{

	if (!w->head)
		w->head = obj; //n funciona passando direto para a lista pq o head n é null
	else
		append_object(&w->head, &obj);
}
