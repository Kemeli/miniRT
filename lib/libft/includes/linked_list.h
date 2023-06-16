/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:06:58 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/03/23 20:56:17 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H
# include <headers.h>

/******************************************************************************\
* LINKED LIST																   *
\******************************************************************************/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @brief Allocates (with malloc(3)) and returns a new node.
 * The member variable ’content’ is initialized with
 * the value of the parameter ’content’. The variable
 * ’next’ is initialized to NULL.
 *
 * @param content The content to create the node with.
 * @return The new node
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Adds the node ’new’ at the beginning of the list.
 *
 * @param lst The address of a pointer to the first link of a list
 * @param new The address of a pointer to the node to be
 * @return
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of nodes in a list.
 *
 * @param lst The beginning of the list.
 * @return The length of the list
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Returns the last node of the list.
 *
 * @param lst The beginning of the list.
 * @return Last node of the list
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Adds the node ’new’ at the end of the list.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 * @return
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Takes as a parameter a node and frees the memory of
 * the node’s content using the function ’del’ given
 * as a parameter and free the node. The memory of
 * ’next’ must not be freed.
 *
 * @note THIS FUNCTION DOES NOT HANDLE RELINKS
 *
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
 * @return
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Deletes and frees the given node and every
 * successor of that node, using the function ’del’
 * and free(3).
 * Finally, the pointer to the list must be set to
 * NULL.
 *
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete the content of the node.
 * @return
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node.
 *
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @return
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node. Creates a new
 * list resulting of the successive applications of
 * the function ’f’. The ’del’ function is used to
 * delete the content of a node if needed.
 *
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content
 * 		of a node if needed.
 * @return The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/******************************************************************************\
* DOUBLY LINKED LIST														   *
\******************************************************************************/

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

t_dlist	*ft_dlstnew(void *content);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *new);
void	ft_dlstadd_begin(t_dlist **lst, t_dlist *new);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);
t_dlist	*ft_dlstlast(t_dlist *lst);
t_dlist	*ft_dlstfirst(t_dlist *lst);
int		ft_dlstsize(t_dlist *lst);
void	ft_dlstdelone(t_dlist *lst, void (*del)(void *));
void	ft_dlstclear(t_dlist **lst, void (*del)(void *));
void	ft_dlstiter(t_dlist *lst, void (*f)(void *));
t_dlist	*ft_dlstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *));

#endif
