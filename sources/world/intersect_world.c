#include <minirt.h>

static void	bubble_sort(t_list **head);

t_intersect	*intersect_world(t_world *world, t_ray *ray)
{
	t_intersect	*xs;
	t_intersect	*temp;
	t_list		*aux;

	aux = world->head;
	xs = intersect(&((t_node *)aux->content)->object, ray);
	aux = aux->next;
	while (aux)
	{
		temp = intersect(&((t_node *)aux->content)->object, ray);
		ft_lstadd_back(&xs->head, temp->head);
		free(temp);
		aux = aux->next;
	}
	bubble_sort(&(xs->head));
	xs->count = ft_lstsize(xs->head);
	return (xs);
}

static int	ft_is_sorted(t_list **list)
{
	int		flag;
	t_list	*temp;

	flag = 0;
	temp = *list;
	while (temp->next)
	{
		if (((t_node *)temp->content)->t > ((t_node *)temp->next->content)->t)
			flag = 1;
		else if (flag == 1)
			break ;
		temp = temp->next;
	}
	return (flag);
}

static void	bubble_sort(t_list **head)
{
	t_list	*temp;
	t_list	*aux;
	t_list	*prev;

	if (!head || !*head)
		return ;
	while (ft_is_sorted(head))
	{
		temp = *head;
		prev = NULL;
		while (temp->next)
		{
			if (((t_node *)temp->content)->t > ((t_node *)temp->next->content)->t)
			{
				aux = temp->next;
				temp->next = aux->next;
				aux->next = temp;
				if (prev)
					prev->next = aux;
				else
					*head = aux;
				prev = aux;
			}
			else
			{
				prev = temp;
				temp = temp->next;
			}
		}
	}
}
