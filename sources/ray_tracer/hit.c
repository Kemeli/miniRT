#include <minirt.h>

t_node	*hit(t_intersect *xs)
{
	t_node	*hit;
	t_node	*curr;

	hit = NULL;
	curr = xs->head;
	while (curr)
	{
		if (curr->t > 0)
		{
			if (hit == NULL)
				hit = curr;
			else if (curr->t < hit->t)
				hit = curr;
		}
		curr = curr->next;
	}
	return (hit);
}

//create sort list of intersections
