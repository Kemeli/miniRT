#include <minirt.h>

t_node	*hit(t_intersect *xs)
{
	t_node	*hit;
	t_list	*aux;

	hit = NULL;
	aux = xs->head;
	while (aux)
	{
		if (((t_node*)aux->content)->t > 0)
		{
			if (hit == NULL)
				hit = (t_node*)aux->content;
			else if (((t_node*)aux->content)->t < hit->t)
				hit = (t_node*)aux->content;
		}
		aux = aux->next;
	}
	return (hit);
}

//create sort list of intersections..?
