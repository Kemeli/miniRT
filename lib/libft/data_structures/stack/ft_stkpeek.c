/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpeek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:41:38 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/24 19:08:31 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_stkpeek_head(t_stack *stack)
{
	if (!stack->head)
		return (NULL);
	return (stack->head->content);
}

void	*ft_stkpeek_foot(t_stack *stack)
{
	if (!stack->foot)
		return (NULL);
	return (stack->foot->content);
}
