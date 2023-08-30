#include <minirt.h>
#include <time.h>

// int	is_ordered(int *numbers, int index, int size)
// {
// 	while (index < size)
// 	{
// 		if (numbers[index] > numbers[index + 1])
// 			return (0);
// 		index++;
// 	}
// 	return (1);
// }

// void	order_array(int *numbers, int index, int pivot)
// {
// 	int	mid;
// 	int	aux;

// 	mid = index;
// 	aux = 0;
// 	if (!is_ordered(numbers, index, pivot))
// 	{
// 		while (numbers[index] != numbers[pivot])
// 		{
// 			if (numbers[index] < numbers[pivot])
// 			{
// 				aux = numbers[index];
// 				numbers[index] = numbers[mid];
// 				numbers[mid] = aux;
// 				mid++;
// 			}
// 			index++;
// 		}
// 		aux = numbers[pivot];
// 		numbers[pivot] = numbers[mid];
// 		numbers[mid] = aux;
// 		order_array(numbers, 0, mid - 1);
// 		order_array(numbers, mid + 1, pivot);
// 	}
// }

void	ft_lstswap(t_list *a, t_list *b)
{
	t_list	*aux;

	aux = a;
	a = b;
	b = aux;
}

void	sort(t_list **head)
{
	t_list	*aux;

	aux = (*head);
	while (aux && aux->next)
	{
		if (((t_node *)aux->content)->t < ((t_node *)aux->next->content)->t)
		{
			aux = aux->next;

		}
		else
		{

			ft_lstswap(aux, aux->next);

			aux = (*head);
			aux = aux->next;
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
	sort(&(xs->head));
	xs->count = ft_lstsize(xs->head);
	return (xs);
}
