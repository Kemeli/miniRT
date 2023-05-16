#ifndef MINIRT_H
# define MINIRT_H
# include <stdlib.h>
# include <math.h>

typedef	float*	t_tuple;

t_tuple	tuple(float x, float y, float z, float w);
t_tuple vector(float x, float y, float z);
t_tuple point(float x, float y, float z);
t_tuple	subtract(t_tuple a, t_tuple b);
char	compare_tuples(t_tuple a, t_tuple b);
t_tuple addition(t_tuple point, t_tuple vector);
t_tuple	scalar_multiplication(t_tuple tuple_a, float times_to_multiply);
t_tuple scalar_division(t_tuple tuple_a, float times_to_divide);

#endif
