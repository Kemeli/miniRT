#include <minirt.h>

char	error_msg(char *error_message)
{
	printf ("ERROR\n");
	printf ("%s\n", error_message);
	return (0);
}

void	*error_msg_scene(char *error_message)
{
	printf ("ERROR\n");
	printf ("%s\n", error_message);
	return (NULL);
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
		w->head = obj;
	else
		append_object(&w->head, &obj);
}

int	count_infos(char **infos)
{
	int	i;

	i = 0;
	while (infos[i])
		i++;
	return (i - 1);
}
