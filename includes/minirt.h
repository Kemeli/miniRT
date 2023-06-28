#ifndef MINIRT_H
# define MINIRT_H
# include <stdlib.h>
# include <math.h>
# include <libft.h>
# include "mlx.h"
# include "mlx_int.h"

#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif

#define SPHERE 1

typedef	float*	t_tuple;

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_sphere
{
	t_tuple	center;
	float	radius;
	float	**transform;
}	t_sphere;

typedef struct s_node
{
	float			t;
	void			*object;
	struct s_node	*next;
}	t_node;

typedef struct s_intersect
{
	t_node	*head;
	int		count;
}	t_intersect;

t_tuple	tuple(float x, float y, float z, float w);
t_tuple	vector(float x, float y, float z);
t_tuple	point(float x, float y, float z);
t_tuple	subtract(t_tuple a, t_tuple b);
t_tuple	negative(t_tuple v);
char	compare_tuples(t_tuple a, t_tuple b);
t_tuple	tuple_addition(t_tuple point, t_tuple vector);
t_tuple	multiply_tuple_by_scalar(t_tuple tuple_a, float times_to_multiply);
t_tuple	scalar_division(t_tuple tuple_a, float times_to_divide);
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
float	determinant(float **matrix);
float	**inverse(float **matrix);
char	compare_floats(float n1, float n2);
float	**translation(float x, float y, float z);
float	**scaling(float x, float y, float z);
float	**rotation_x(float radian);
float	**rotation_y(float radian);
float	**rotation_z(float radian);
float	**shearing(int axis, float value);
t_ray	*create_ray(t_tuple origin, t_tuple direction);
t_tuple	get_point_position(t_ray *ray, float t);
t_sphere	*create_sphere(void);
t_intersect	*intersect_sphere(t_sphere *sphere, t_ray *ray);
t_node	*new_intersection(float t, void *object);
void	free_list(t_intersect *list);
t_intersect	*add_intersection_to_list(t_intersect *list, t_node *new);
t_node	*hit(t_intersect *xs);
t_ray	*transform_ray(t_ray *ray, float **matrix);
void	set_transform(t_sphere **sphere, float **translation);
t_tuple	normal_at(t_sphere *sphere, t_tuple point);
t_tuple	reflect(t_tuple in, t_tuple normal);

#endif
