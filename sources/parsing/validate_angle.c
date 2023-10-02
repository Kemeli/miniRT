/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_angle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:25:28 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:25:29 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	validate_angle(char *angle)
{
	int		i;
	char	*s_angle;
	double	f_angle;

	i = 0;
	if (!is_double(angle))
		return (-1);
	while (angle[i])
		i++;
	s_angle = ft_substr(angle, 0, i);
	f_angle = ft_atof(s_angle);
	free(s_angle);
	if (f_angle < 0 || f_angle > 180)
		return (-1);
	return (f_angle);
}
