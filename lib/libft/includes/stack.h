/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:54:34 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/03/07 22:12:39 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <headers.h>
# include <linked_list.h>

/******************************************************************************\
* STACK																		   *
\******************************************************************************/

typedef struct s_stack
{
	size_t	size;
	t_dlist	*head;
	t_dlist	*foot;
}	t_stack;

/**
 * Allocates (with malloc(3)) and returns a new stack.
 *
 * @param content value for the new element of the stack
 * @return A stack with the passed content
 */
t_stack	*ft_stknew(void *content);

/**
 * Allocates (with malloc(3)) and initiate the stack passed pointer with NULL.
 *
 * @param stack The stack to be initiated
 */
void	ft_stkinit(t_stack **stack);

/**
 * Adds a new item to the top of the stack,
 * replacing the current head to the new pushed element.
 * If there is no head, the new element turns into the head.
 *
 * @param stack The stack to be modified
 * @param content value for the new element of the stack
 * @return A stack with the passed content
 */
t_stack	*ft_stkpush(t_stack *stack, void *content);

/**
 * Removes the first item of the stack,
 * decrementing the stack size and moving your head
 *
 * @param stack The stack to be modified
 * @param del The function to delete the content of the stack
 */
void	ft_stkpop(t_stack *stack, void (*del)(void *));

/**
 * Delete and frees the entire stack
 *
 * @param stack The stack to be deleted
 * @param del The function to delete the content of the stack
 */
void	ft_stkclear(t_stack *stack, void (*del)(void *));

/**
 * Get the element that is in the top of the stack (the head)
 *
 * @param stack The stack to be analyzed
 * @return The stored content inside the head
 */
void	*ft_stkpeek_head(t_stack *stack);

/**
 * Get the element that is in the bottom of the stack (the foot)
 *
 * @param stack The stack to be analyzed
 * @return The stored content inside the foot
 */
void	*ft_stkpeek_foot(t_stack *stack);

/**
 * Checks if the stack is empty
 *
 * @param stack The stack to be analyzed
 * @return A boolean value
 */
t_bool	ft_stkis_empty(t_stack *stack);

#endif
