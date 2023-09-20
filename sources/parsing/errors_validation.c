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
