#include <minirt.h>

void	ft_free_ptr(void **ptr) //tirar do .h
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_elements(t_rt *rt)
{
	if (rt->c_coordinates)
		ft_free_ptr((void *) &rt->c_coordinates);
	if (rt->c_orientation)
		ft_free_ptr((void *) &rt->c_orientation);
	if (rt->l_coordinates)
		ft_free_ptr((void *) &rt->l_coordinates);
	if (rt->l_color)
		ft_free_ptr((void *) &rt->l_color);
}

void	free_rt(t_rt *rt)
{
	free_elements(rt);
	ft_free_ptr((void *) &rt);
}
