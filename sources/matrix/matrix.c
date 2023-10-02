/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:23:48 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:23:49 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_matrix	matrix(unsigned int n)
{
	t_matrix		m;
	unsigned int	i;

	if (n == 0)
		return (NULL);
	i = 0;
	m = ft_calloc(n + 1, sizeof(double *));
	while (i < n)
	{
		m[i] = ft_calloc(n + 1, sizeof(double));
		i++;
	}
	m[i] = NULL;
	return (m);
}

double	**identity_matrix(unsigned int n)
{
	t_matrix		m;
	unsigned int	i;
	unsigned int	j;

	m = matrix(n);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (i == j)
				m[i][j] = 1;
			else
				m[i][j] = 0;
			j++;
		}
		i++;
	}
	return (m);
}

void	free_matrix(t_matrix m)
{
	unsigned int	i;

	i = 0;
	while (m[i])
	{
		ft_free_ptr((void *) &m[i]);
		i++;
	}
	ft_free_ptr((void *) &m);
}
