#include <minirt.h>

static void	bubble_sort(t_list **head);

t_intersect	*intersect_world(t_world *world, t_ray *ray)
{
	t_intersect	*xs;
	t_intersect	*temp;
	t_list		*s;

	xs = ft_calloc(1, sizeof(t_intersect));
	s = world->head;
	temp = intersect_sphere(((t_node *)s->content)->object, ray);
	s = s->next;
	xs->head = temp->head;
	xs->count = temp->count;
	free(temp);
	temp = intersect_sphere(((t_node *)s->content)->object, ray);
	ft_lstadd_back(&(xs->head), temp->head);
	xs->count += temp->count;
	bubble_sort(&(xs->head));
	free(temp);
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
	t_list	*slow;
	t_list	*fast;
	float	temp;

	slow = *head;
	fast = (*head)->next;
	while (ft_is_sorted(head))
	{
		if (((t_node *)slow->content)->t > ((t_node *)fast->content)->t)
		{
			temp = ((t_node *)slow->content)->t;
			((t_node *)slow->content)->t = ((t_node *)fast->content)->t;
			((t_node *)fast->content)->t = temp;
		}
		slow = slow->next;
		fast = fast->next;
		if (!fast)
		{
			slow = *head;
			fast = (*head)->next;
		}
	}
}
