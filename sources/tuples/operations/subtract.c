/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtract.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:27:53 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:27:55 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	subtract(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result = tuple(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
	return (result);
}
