#include <minirt.h>

t_node	*hit(t_intersect *xs)
{
	t_node	*hit;

	hit = NULL;
	while (xs->head)
	{
		if (xs->head->t > 0)
		{
			if (hit == NULL)
				hit = xs->head;
			else if (xs->head->t < hit->t)
				hit = xs->head;
		}
		// if (xs->head->object)
		// 	hit->object = xs->head->object;
		xs->head = xs->head->next;
	}
	return (hit);
}

//create sort list of intersections..?
