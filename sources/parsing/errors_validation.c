#include <minirt.h>

char	input_error(char *message, char **infos)
{
	free_split(infos);
	return(error_msg(message));
}

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
