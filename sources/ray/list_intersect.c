#include <minirt.h>

t_node	*new_intersection(float t, void *object)
{
	t_node	*intersect;

	intersect = ft_calloc(1, sizeof(t_node));
	intersect->t = t;
	intersect->object = object;
	return (intersect);
}

t_intersect	*add_intersection_to_list(t_intersect *list, t_node *new)
{
	t_node	*aux;

	if (list == NULL)
	{
		list = ft_calloc(1, sizeof(t_intersect));
		list->head = new;
		return (list);
	}
	else
	{
		aux = list->head;
		while (aux->next)
			aux = aux->next;
		new->next = NULL;
		aux->next = new;
	}
	return (list);
}

void	free_list(t_intersect *list)
{
	t_node	*aux;

	aux = list->head;
	while (list->head)
	{
		aux = list->head->next;
		free(list->head);
		list->head = aux;
	}
	free(list);
}
