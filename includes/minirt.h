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
int		compare_matrices(float **matrix_A, float **matrix_B);
t_tuple	multiply_colors(t_tuple c1, t_tuple c2);
float	**matrix(unsigned int n);
void	free_matrix(float **m);
float	**multiply_matrix(float **matrix_A, float **matrix_B);
t_tuple	multiply_matrix_with_tuple(float **matrix_A, t_tuple tuple_A);
float	**transpose_matrix(float **matrix_A);
float	determinant_2X2_matrix(float **matrix);
float	**identity_matrix(unsigned int n);
float	**submatrix(float **matrix, int row, int col);
int		get_size(float **matrix);
float	minor(float **matrix, int i, int j);
float	cofactor(float **matrix, int i, int j);

#endif
