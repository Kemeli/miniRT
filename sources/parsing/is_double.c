/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:25:17 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:25:18 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

char	is_double(char *str)
{
	if (*str == '-')
		str++;
	if (!ft_isdigit(*str) || (ft_strchr(str, '.') != ft_strrchr(str, '.')))
		return (0);
	while (*str)
	{
		if (*str == '.')
			str++;
		if (!ft_isdigit(*str) && !ft_strrchr(".\0", *str))
			return (0);
		str++;
	}
	return (1);
}
