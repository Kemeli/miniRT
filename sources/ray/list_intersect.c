#include <minirt.h>

t_intersect	*new_intersection(float t, void *object)
{
	t_intersect	*intersect;

	intersect = ft_calloc(1, sizeof(t_intersect));
	intersect->t = t;
	intersect->object = object;
	intersect->next = NULL;
	return (intersect);
}

t_intersect	*add_intersection_to_list(t_intersect *list, t_intersect *new)
{
	t_intersect	*aux;

	if (list == NULL)
		return (new);
	else
	{
		aux = list;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	return (list);
}

void	free_list(t_intersect *list)
{
	t_intersect	*aux;

	aux = list;
	while (list)
	{
		aux = list->next;
		free(list);
		list = aux;
	}
}
