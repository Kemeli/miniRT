/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 01:51:46 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/02/24 00:59:35 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;

	slen = ft_strlen(src);
	dlen = 0;
	while (dst[dlen] && dlen < dsize)
		dlen++;
	i = 0;
	if (dlen < dsize)
	{
		while (i + dlen < (dsize - 1) && src[i])
		{
			dst[i + dlen] = src[i];
			i++;
		}
		dst[i + dlen] = '\0';
	}
	return (dlen + slen);
}
