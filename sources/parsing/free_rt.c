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

// void	free_objects(t_rt *rt)
// {
// 	if (rt->sp_coordinates)
// 		ft_free_ptr((void *) &rt->sp_coordinates);
// 	if (rt->sp_color)
// 		ft_free_ptr((void *) &rt->sp_color);
// 	if (rt->pl_coordinates)
// 		ft_free_ptr((void *) &rt->pl_coordinates);
// 	if (rt->pl_normal)
// 		ft_free_ptr((void *) &rt->pl_normal);
// 	if (rt->pl_color)
// 		ft_free_ptr((void *) &rt->pl_color);
// 	if (rt->cy_coordinates)
// 		ft_free_ptr((void *) &rt->cy_coordinates);
// 	if (rt->cy_normal)
// 		ft_free_ptr((void *) &rt->cy_normal);
// 	if (rt->cy_color)
// 		ft_free_ptr((void *) &rt->cy_color);
// }

void	free_rt(t_rt *rt)
{
	free_elements(rt);
	// free_objects(rt);
	ft_free_ptr((void *) &rt);
}
