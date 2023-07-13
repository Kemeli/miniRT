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

void	free_list(t_intersect *list)
{
	ft_lstclear(&list->head, free);
	free(list);
}
