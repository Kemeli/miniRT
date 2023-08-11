#include <minirt.h>

int	skip_spaces(int index, char *str)
{
	while(str[index] && str[index] == ' ')
		index++;
	return (index);
}

int	go_through_char(int index, char *str)
{
	while(str[index] && str[index] != ' ')
		index++;
	return (index);
}

void	error_and_exit(char *error_message)
{
	printf ("ERROR\n");
	printf ("%s\n", error_message);
	exit (0);
}
