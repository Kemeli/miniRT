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
	int		pos;
	char	**num;

	pos = 0;
	i = 0;
	num = ft_split(str, ',');
	while (num && num[i])
	{
		if(is_double(num[i]))
			n[pos++] = ft_atof(num[i]);
		else
			return (NULL);
		i++;
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
