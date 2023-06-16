/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:41:38 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/24 19:08:31 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_stack	*ft_stkpush(t_stack *stack, void *content)
{
	t_dlist	*new_node;

	new_node = ft_dlstnew(content);
	if (!new_node)
		return (NULL);
	if (stack->size == 0 || !stack->head || !stack->foot)
	{
		stack->head = new_node;
		stack->foot = stack->head;
	}
	else
	{
		ft_dlstadd_back(&stack->head, new_node);
		stack->head = stack->head->next;
	}
	stack->size += 1;
	return (stack);
}
