#include <minirt.h>
#include <time.h>
#include <minirt.h>

typedef struct s_aux
{
	t_node	*temp;
	t_node	*ptr;
	t_node	*prev;
}	t_aux;

static int	ft_is_sorted(t_node **list)
{
	int		flag;
	t_node	*temp;

	if(!(*list) || !(*list)->next)
		return (0);
	flag = 0;
	temp = *list;
	while (temp->next)
	{
		if (temp->t > temp->next->t)
			flag = 1;
		else if (flag == 1)
			break ;
		temp = temp->next;
	}
	return (flag);
}

void	curr_t_bigger_than_next_t(t_aux *aux, t_node **head)
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

static void	bubble_sort(t_node **head)
{
	t_aux	aux;

	while (ft_is_sorted(head))
	{
		aux.temp = *head;
		aux.prev = NULL;
		while (aux.temp->next)
		{
			if (aux.temp->t > aux.temp->next->t)
				curr_t_bigger_than_next_t(&aux, head);
			else
			{
				aux.prev = aux.temp;
				aux.temp = aux.temp->next;
			}
		}
	}
}


// void	swap_intersections(t_node **a, t_node **b)
// {
// 	t_node	*aux;

// 	aux = (*a);
// 	(*a) = (*b);
// 	(*b) = aux;
// }

// void	sort(t_node **head)
// {
// 	t_node	*aux;

// 	aux = (*head);
// 	while (aux && aux->next)
// 	{
// 		if (aux->t < aux->next->t)
// 			aux = aux->next;
// 		else
// 		{
// 			swap_intersections(&aux, &aux->next);
// 			aux = (*head);
// 			aux = aux->next;
// 		}
// 	}
// }

t_intersect	*intersect_world(t_world *world, t_ray *ray)
{
	t_intersect	*xs;
	t_intersect	*temp;
	t_object	*aux;

	aux = world->head;
	// xs = intersect(&aux, ray);
	// aux = aux->next;
	xs = ft_calloc(1, sizeof(t_intersect)); //talvez isso seja um problema no "append_node"
	while (aux)
	{
		temp = intersect(&aux, ray);
		append_node(&xs->head, temp->head);
		free(temp);
		aux = aux->next;
	}
	bubble_sort(&(xs->head));
	xs->count = intersect_lst_size(xs->head);
	return (xs);
}
