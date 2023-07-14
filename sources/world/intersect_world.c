#include <minirt.h>

static void	bubble_sort(t_list **head);

t_intersect	*intersect_world(t_world *world, t_ray *ray)
{
	t_intersect	*xs;
	t_intersect	*temp;
	t_list		*obj;

	obj = world->head;
	xs = intersect(((t_node *)obj->content)->object, ray);
	obj = obj->next;
	while (obj)
	{
		temp = intersect(((t_node *)obj->content)->object, ray);
		xs->count += temp->count;
		ft_lstadd_back(&(xs->head), temp->head);
		free(temp);
		obj = obj->next;
	}
	bubble_sort(&(xs->head));
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
