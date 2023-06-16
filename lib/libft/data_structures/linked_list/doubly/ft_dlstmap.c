/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:08:05 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/24 19:07:47 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_dlist	*ft_dlstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*result;
	t_dlist	*temp;
	t_dlist	*changed_node;

	result = NULL;
	if (!lst || !f || !del)
		return (result);
	temp = ft_dlstfirst(lst);
	while (temp)
	{
		changed_node = ft_dlstnew(f(temp->content));
		if (!changed_node)
		{
			ft_dlstclear(&changed_node, del);
			return (NULL);
		}
		ft_dlstadd_back(&result, changed_node);
		temp = temp->next;
	}
	return (result);
}
