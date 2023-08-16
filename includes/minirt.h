#ifndef MINIRT_H
# define MINIRT_H
# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# define EPSILON 0.00001

# define TRUE 1
# define FALSE 0

typedef float*	t_tuple;
typedef float**	t_matrix;

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_material
{
	t_tuple	color;
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
}	t_material;

typedef struct s_cylinder
{
	float	minimum;
	float	maximum;
	char	closed;
}	t_cylinder;

typedef struct s_plane
{
	char	pass;
}	t_plane;

typedef struct s_sphere
{
	t_tuple		center;
	float		radius;
}	t_sphere;

typedef struct s_object
{
	char		shape; // s = sphere, p = plane e c = cylinder
	union
	{
		t_sphere	*sphere;
		t_plane		*plane;
		t_cylinder	*cylinder;
	};
	t_ray		*saved_ray;
	float		**transform;
	t_material	*material;
	void		(*change_my_material)(struct s_object *obj, t_material *m);
}	t_object;

typedef struct s_node
{
	float		t;
	t_object	*object;
}	t_node;

typedef struct s_intersect
{
	t_list	*head;
	int		count;
}	t_intersect;

typedef struct s_point_light
{
	t_tuple	position;
	t_tuple	intensity;
}	t_point_light;

typedef struct s_lighting
{
	t_material		*material;
	t_point_light	*light;
	t_tuple			position;
	t_tuple			eye;
	t_tuple			normal;
	int				in_shadow;
}	t_lighting;

typedef struct s_world
{
	t_list			*head;
	t_point_light	*light;
}	t_world;

typedef struct s_comps
{
	float		t;
	t_object	*object;
	t_tuple		point;
	t_tuple		eye;
	t_tuple		normal;
	int			inside;
	t_tuple		over_point;
}	t_comps;

typedef struct s_camera
{
	float		hsize;
	float		vsize;
	float		field_of_view;
	float		pixel_size;
	float		half_width;
	float		half_height;
	t_matrix	transform;
}	t_camera;

typedef struct s_image
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}t_image;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_camera	*c;
	t_world		*w;
	t_image		*img;
}t_data;

typedef struct s_rt
{
	char	*scene_name;
	char	*cpy_scene;

	t_tuple	a_color;
	float	a_ratio;

	t_tuple	c_coordinates;
	t_tuple	c_normal;
	float	c_fov;

	t_tuple	l_coordinates;
	t_tuple	l_color;
	float	l_brightness;

	t_tuple	sp_coordinates;
	t_tuple	sp_color;
	float	sp_diameter;

	t_tuple	pl_coordinates;
	t_tuple	pl_normal;
	t_tuple	pl_color;

	t_tuple	cy_coordinates;
	t_tuple	cy_normal;
	float	cy_diameter;
	float	cy_height;
	t_tuple	cy_color;

}	t_rt;
//tuples são float e as cores são int, pode dar erro

t_tuple			tuple(float x, float y, float z, float w);
t_tuple			vector(float x, float y, float z);
t_tuple			point(float x, float y, float z);
t_tuple			subtract(t_tuple a, t_tuple b);
t_tuple			negative(t_tuple v);
char			compare_tuples(t_tuple a, t_tuple b);
void			ft_swap(void *a, void *b);
t_tuple			tuple_addition(t_tuple point, t_tuple vector);
t_tuple			multiply_tuple_by_scalar(
					t_tuple tuple_a, float times_to_multiply);
t_tuple			scalar_division(t_tuple tuple_a, float times_to_divide);
float			magnitude(t_tuple v);
t_tuple			normalize(t_tuple v);
t_tuple			cross(t_tuple a, t_tuple b);
float			dot(t_tuple v, t_tuple w);
t_tuple			color(float r, float g, float b);
int				compare_matrices(t_matrix matrix_A, t_matrix matrix_B);
t_tuple			multiply_colors(t_tuple c1, t_tuple c2);
t_matrix		matrix(unsigned int n);
void			free_matrix(t_matrix m);
t_matrix		multiply_matrix(t_matrix matrix_A, t_matrix matrix_B);
t_tuple			multiply_matrix_with_tuple(t_matrix matrix_A, t_tuple tuple_A);
t_matrix		transpose_matrix(t_matrix matrix_A);
float			determinant_2X2_matrix(t_matrix matrix);
t_matrix		identity_matrix(unsigned int n);
t_matrix		submatrix(t_matrix matrix, int row, int col);
int				get_size(t_matrix matrix);
float			minor(t_matrix matrix, int i, int j);
float			cofactor(t_matrix matrix, int i, int j);
float			determinant(t_matrix matrix);
t_matrix		inverse(t_matrix matrix);
char			compare_floats(float n1, float n2);
t_matrix		translation(float x, float y, float z);
t_matrix		scaling(float x, float y, float z);
t_matrix		rotation_x(float radian);
t_matrix		rotation_y(float radian);
t_matrix		rotation_z(float radian);
t_matrix		shearing(int axis, float value);
t_ray			*create_ray(t_tuple origin, t_tuple direction);
t_tuple			get_point_position(t_ray *ray, float t);
t_sphere		*create_sphere(void);
void			free_sphere(t_sphere *s);
void			change_material(t_object *obj, t_material *m);
t_intersect		*intersect_sphere(t_object *object);
t_list			*new_intersection(float t, t_object *object);
void			free_intersections(t_intersect *list);
t_intersect		*add_intersection_to_list(t_intersect *list, t_node *new);
t_node			*hit(t_intersect *xs);
t_ray			*transform_ray(t_ray *ray, t_matrix matrix);
void			set_transform(t_object **obj, t_matrix translation);
t_tuple			normal_at(t_object *object, t_tuple point);
t_tuple			reflect(t_tuple in, t_tuple normal);
t_point_light	*point_light(t_tuple position, t_tuple intensity);
t_material		*material(void);
void			free_material(t_material *m);
t_tuple			lighting(t_lighting *l);
t_tuple			ligth_vector(t_lighting *l);
void			free_lighting(t_lighting *l);
void			free_ray(t_ray *ray);
t_world			*create_world(void);
t_world			*default_world(void);
t_object		*create_object(char shape);
void			free_world(t_world *world);
t_intersect		*intersect_world(t_world *world, t_ray *ray);
t_comps			*prepare_computations(t_node *hit, t_ray *ray);
void			free_comps(t_comps *comps);
t_intersect		*intersect(t_object **object, t_ray *ray);
void			free_object(t_object *object);
t_tuple			shade_hit(t_world *world, t_comps *comps);
t_tuple			color_at(t_world *w, t_ray *r);
t_matrix		view_transform(t_tuple from, t_tuple to, t_tuple direction);
t_camera		*camera(float hsize, float vsize, float field_of_view);
void			free_camera(t_camera *c);
t_ray			*ray_for_pixel(t_camera *c, float px, float py);
void			render(t_data *data);
char			is_shadowed(t_world *world, t_tuple point);
t_plane			*create_plane(void);
t_intersect		*intersect_plane(t_object *object, t_ray *ray);
t_tuple			local_normal_at(t_object *object, t_tuple local_point);
t_cylinder		*create_cylinder(void);
t_intersect		*intersect_cylinder(t_object *object, t_ray *ray);
float			is_btwen_range(char *ratio, char *r0, char *r1);
t_tuple			validate_color(char *str);
float			ft_atof(const char *str);
t_tuple			char_to_color(char *str);
t_tuple			validate_coordinates(char *str);
t_tuple			validate_normal(char *str);
float			validate_angle(char *angle);
char			validate_c(char *C_line, t_rt *rt);
int				skip_spaces(int index, char *str);
int				go_through_char(int index, char *str);
void			error_and_exit(char *error_message);
char			validate_a(char *A_line, t_rt *rt);
void			validate_scene(t_rt *rt);
void			free_split(char **split);
char			validate_l(char *line, t_rt *rt);
void			count_comma(int *index, int *comma);
float			get_float(char *str, int i, int j);
int				go_through_num(char *str, int i);
float			*validate_tuple(char *str, float *n);
char			is_float(char *str);
char			validate_sp(char *line, t_rt *rt);
char			validate_pl(char *element, t_rt *rt);
char			validate_cy(char *element, t_rt *rt);
float			verify_and_get_float(char *str);

#endif
