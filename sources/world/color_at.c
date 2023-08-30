#include <minirt.h>
#include <time.h>


t_tuple	color_at(t_world *w, t_ray *r)
{
	t_intersect	*xs;
	t_comps		*comps;
	t_tuple		c;
	t_node		*the_hit;

	clock_t start_time, end_time;
    double cpu_time_used;
    start_time = clock();  // Record the start time
	printf("entrando...\n");
	xs = intersect_world(w, r);

	end_time = clock();  // Record the end time
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;  // Calculate the time used in seconds
    printf("Time taken by the function: %f seconds\n", cpu_time_used);

	the_hit = hit(xs);
	if (the_hit)
	{
		comps = prepare_computations(the_hit, r);
		c = shade_hit(w, comps);
		free_comps(comps);
	}
	else
		c = color(0, 0, 0);
	free_intersections(xs);
	return (c);
}

