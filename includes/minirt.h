#ifndef MINIRT_H
# define MINIRT_H
# include <stdlib.h>
# include <math.h>

typedef	float*	t_tuple;

t_tuple	tuple(float x, float y, float z, float w);
t_tuple vector(float x, float y, float z);
t_tuple point(float x, float y, float z);
char	compare_tuples(t_tuple a, t_tuple b);

#endif
