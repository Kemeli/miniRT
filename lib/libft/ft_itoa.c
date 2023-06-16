/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:39:25 by kdaiane-          #+#    #+#             */
/*   Updated: 2022/06/23 02:50:39 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_tostr(char *str, int n, int size)
{
	if (n >= 0)
	{
		while (size--)
		{
			str[size] = (n % 10) + '0';
			n = n / 10;
		}
	}
	else
	{
		while (--size)
		{
			str[size] = (n % 10) * -1 + '0';
			n = n / 10;
		}
		str[size] = '-';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		aux;
	int		size;

	if (n >= 0)
		size = 1;
	else
		size = 2;
	aux = n / 10;
	while (aux)
	{
		size++;
		aux = aux / 10;
	}
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	ft_tostr(str, n, size);
	return (str);
}
