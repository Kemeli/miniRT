#include <minirt.h>

t_node	*hit(t_intersect *xs)
{
	t_node	*hit;
	t_node	*aux;

	hit = NULL;
	aux = xs->head;
	while (aux)
	{
		if (aux->t > 0)
		{
			if (hit == NULL)
				hit = aux;
			else if (aux->t < hit->t)
				hit = aux;
		}
		aux = aux->next;
	}
	return (hit);
}

