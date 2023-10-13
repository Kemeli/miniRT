/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:28:28 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/28 01:38:41 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	get_point_position(t_ray *ray, double t)
{
	t_tuple	position;
	t_tuple	multiplication_result;

	multiplication_result = multiply_tuple_by_scalar(ray->direction, t);
	position = tuple_addition(ray->origin, multiplication_result);
	free(multiplication_result);
	return (position);
}

t_comps	*prepare_computations(t_node *hit, t_ray *ray)
{
	t_comps	*comps;
	double	dot_p;
	t_tuple	temp;
	t_tuple	mult;

	comps = ft_calloc(1, sizeof(t_comps));
	comps->t = hit->t;
	comps->object = hit->object;
	comps->point = get_point_position(ray, comps->t);
	comps->eye = negative(ray->direction);
	comps->normal = normal_at(comps->object, comps->point);
	comps->inside = FALSE;
	dot_p = dot(comps->normal, comps->eye);
	if (dot_p < 0)
	{
		comps->inside = TRUE;
		temp = comps->normal;
		comps->normal = negative(temp);
		free(temp);
	}
	mult = multiply_tuple_by_scalar(comps->normal, EPSILON);
	comps->over_point = tuple_addition(comps->point, mult);
	free(mult);
	return (comps);
}

void	free_comps(t_comps *comps)
{
	free(comps->point);
	free(comps->eye);
	free(comps->normal);
	free(comps->over_point);
	free(comps);
}
