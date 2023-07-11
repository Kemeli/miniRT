#include <minirt.h>

t_list	*new_intersection(float t, t_object *object)
{
	t_node	*intersect;
	t_list	*list;

	intersect = ft_calloc(1, sizeof(t_node));
	intersect->t = t;
	intersect->object = object;
	list = ft_lstnew(intersect);
	return (list);
}

// t_intersect	*add_intersection_to_list(t_intersect *list, t_node *new)
// {
// 	t_node	*aux;

// 	if (list == NULL)
// 	{
// 		list = ft_calloc(1, sizeof(t_intersect));
// 		list->head = new;
// 		return (list);
// 	}
// 	else
// 	{
// 		aux = list->head;
// 		while (aux->next)
// 			aux = aux->next;
// 		new->next = NULL;
// 		aux->next = new;
// 	}
// 	return (list);
// }

// void	free_list(t_intersect *list)
// {
// 	t_node	*aux;

// 	while (list->head)
// 	{
// 		aux = list->head->next;
// 		free(list->head);
// 		list->head = aux;
// 	}
// 	free(list);
// }
