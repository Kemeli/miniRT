/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:41:38 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/24 19:08:31 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_stkpop(t_stack *stack, void (*del)(void *))
{
	t_dlist	*temp_head_prev;

	if (!stack || !stack->head || !del)
		return ;
	temp_head_prev = stack->head->prev;
	ft_dlstdelone(stack->head, del);
	stack->head = temp_head_prev;
	if (stack->size > 1)
	{
		stack->size -= 1;
		return ;
	}
	stack->size = 0;
	stack->head = NULL;
	stack->foot = NULL;
}
