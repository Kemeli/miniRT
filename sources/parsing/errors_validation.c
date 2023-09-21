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

void	*clean_and_error_msg(char *msg, char *cpy_scene)
{
	free(cpy_scene);
	return (error_msg_scene(msg));
}

char	input_error(char *message, char **infos)
{
	free_split(infos);
	return(error_msg(message));
}

void	free_teste(t_teste *aux)
{
	if (aux->coordinates)
		free(aux->coordinates);
	if (aux->color)
		free(aux->color);
	if (aux->orientation)
		free(aux->orientation);
	free(aux);
}

char	print_error(char *message, char **infos, t_teste *aux)
{
	free_teste(aux);
	free_split(infos);
	return(error_msg(message));
}
