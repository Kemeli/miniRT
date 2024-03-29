/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_orientation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:25:32 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:25:33 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static char	validate_range(double *n)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (fabs(n[i]) > 1.0f && fabs(n[0]) - 1.0f > EPSILON)
			return (0);
		i++;
	}
	return (1);
}

t_tuple	validate_orientation(char *str)
{
	double	n[3];
	double	*normal;
	t_tuple	ret;

	normal = validate_tuple(str, n);
	if (normal && validate_range(normal))
	{
		ret = vector(normal[0], normal[1], normal[2]);
		if (compare_doubles(magnitude(ret), 1))
			return (ret);
		free(ret);
	}
	return (NULL);
}
