/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:29:00 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/29 15:16:56 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	has_sign(char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	return (sign);
}

double	ft_atof(const char *str)
{
	double	result;
	int		sign;
	int		frac_pow;

	result = 0.0;
	frac_pow = 1;
	sign = has_sign((char **)&str);
	while (ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		frac_pow *= 10;
		str++;
	}
	return (sign * result / frac_pow);
}
