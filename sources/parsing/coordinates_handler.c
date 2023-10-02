/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:24:54 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/30 02:19:53 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	*validate_tuple(char *str, double *n)
{
	int		i;
	int		pos;
	char	**num;

	pos = 0;
	i = 0;
	num = ft_split(str, ',');
	while (num && num[i])
	{
		if (is_double(num[i]))
			n[pos++] = ft_atof(num[i]);
		else
		{
			free_split(num);
			return (NULL);
		}
		i++;
	}
	if (pos != 3)
	{
		free_split(num);
		return (NULL);
	}
	free_split(num);
	return (n);
}

t_tuple	validate_coordinates(char *str)
{
	double	n[3];

	if (!validate_tuple(str, n))
		return (NULL);
	if (n[0] < -MAX_RANGE || n[0] > MAX_RANGE
		|| n[1] < -MAX_RANGE || n[1] > MAX_RANGE
		|| n[2] < -MAX_RANGE || n[2] > MAX_RANGE)
		return (NULL);
	return (point(n[0], n[1], n[2]));
}
