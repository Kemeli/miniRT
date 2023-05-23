#ifndef MINIRT_H
# define MINIRT_H
# include <stdlib.h>
# include <math.h>

typedef	float*	t_tuple;

t_tuple	tuple(float x, float y, float z, float w);
t_tuple vector(float x, float y, float z);
t_tuple point(float x, float y, float z);
t_tuple	subtract(t_tuple a, t_tuple b);
t_tuple	negative(t_tuple v);
char	compare_tuples(t_tuple a, t_tuple b);
t_tuple addition(t_tuple point, t_tuple vector);
t_tuple	scalar_multiplication(t_tuple tuple_a, float times_to_multiply);
t_tuple scalar_division(t_tuple tuple_a, float times_to_divide);
float	magnitude(t_tuple v);
t_tuple	normalize(t_tuple v);
t_tuple	cross(t_tuple a, t_tuple b);
float	dot(t_tuple v, t_tuple w);
t_tuple	color(float r, float g, float b);
float	**matrix(unsigned int n);

#endif
