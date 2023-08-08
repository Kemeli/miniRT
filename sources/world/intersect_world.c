#include <minirt.h>

typedef struct s_aux
{
	t_list	*temp;
	t_list	*ptr;
	t_list	*prev;
}	t_aux;

static int	ft_is_sorted(t_list **list)
{
	int		flag;
	t_list	*temp;

	if(!(*list) || !(*list)->next)
		return (0);
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

void	curr_t_bigger_than_next_t(t_aux *aux, t_list **head)
{
	aux->ptr = aux->temp->next;
	aux->temp->next = aux->ptr->next;
	aux->ptr->next = aux->temp;
	if (aux->prev)
		aux->prev->next = aux->ptr;
	else
		(*head) = aux->ptr;
	aux->prev = aux->ptr;
}

static void	bubble_sort(t_list **head)
{
	t_aux	aux;

	while (ft_is_sorted(head))
	{
		aux.temp = *head;
		aux.prev = NULL;
		while (aux.temp->next)
		{
			if (((t_node *)aux.temp->content)->t >
				((t_node *)aux.temp->next->content)->t)
				curr_t_bigger_than_next_t(&aux, head);
			else
			{
				aux.prev = aux.temp;
				aux.temp = aux.temp->next;
			}
		}
	}
}

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

