#include <minirt.h>

void	ft_free_ptr(void **ptr) //tirar do .h
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
