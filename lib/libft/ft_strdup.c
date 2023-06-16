/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 01:35:54 by kdaiane-          #+#    #+#             */
/*   Updated: 2022/06/21 02:51:18 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	len;
	char			*new;

	len = ft_strlen(s);
	new = ft_calloc((len + 1), sizeof(char));
	if (new == NULL)
		return (NULL);
	new = ft_memcpy(new, s, len);
	return (new);
}
