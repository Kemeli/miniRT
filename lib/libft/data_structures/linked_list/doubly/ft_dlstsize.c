/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:42:29 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/24 19:07:47 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_dlstsize(t_dlist *lst)
{
	t_dlist	*current_list;
	int		counter;

	counter = 0;
	if (!lst)
		return (counter);
	current_list = lst;
	while (current_list != NULL)
	{
		counter++;
		current_list = current_list->prev;
	}
	current_list = lst->next;
	while (current_list != NULL)
	{
		counter++;
		current_list = current_list->next;
	}
	return (counter);
}
