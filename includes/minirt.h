/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:45:41 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/29 15:45:41 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <math.h>
# include "libft.h"
# include "mlx.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# define EPSILON 0.00001

# define DESTROY_NOTIFY 17
# define KEY_PRESS 2
# define ESCAPE 65307

# define TRUE 1
# define FALSE 0

# define HEIGHT 700
# define WIDTH 1000

# define POSITIVE "be bigger than 0 up to 1000"
# define COLOR "contain 3 values between 0 and 255 [0,255,180]"
# define COORDINATES "contain 3 values between -1000 and 1000 [6,0,-20]"
# define ORIENTATION "be a normalized vector, range -1 to 1 [0.0,1.0,0.0]"
# define FOV "be a value between 0 and 180"
# define BRIGHTNESS "be a value between 0.0 and 1.0"

# define MAX_RANGE 1000

typedef double*		t_tuple;
typedef double**	t_matrix;

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_material
{
	t_tuple	color;
	t_tuple	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_material;

typedef struct s_cylinder
{
	double	minimum;
	double	maximum;
	char	closed;
	t_tuple	center;
	double	radius;
	double	height;
}	t_cylinder;

typedef struct s_plane
{
	t_tuple	point;
	t_tuple	orientation;
}	t_plane;

typedef struct s_sphere
{
	t_tuple		center;
	double		radius;
}	t_sphere;

typedef struct s_object
{
	char			shape;
	union
	{
		t_sphere	*sphere;
		t_plane		*plane;
		t_cylinder	*cylinder;
	};
	t_tuple			normal;
	double			**transform;
	double			**inverse;
	double			**transpose_inverse;
	t_material		*material;
	struct s_object	*next;
}	t_object;

typedef struct s_node
{
	double			t;
	t_object		*object;
	struct s_node	*next;
}	t_node;

typedef struct s_intersect
{
	t_node	*head;
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
	t_object		*head;
	t_point_light	*light;
	t_tuple			ambient;
}	t_world;

typedef struct s_comps
{
	double		t;
	t_object	*object;
	t_tuple		point;
	t_tuple		eye;
	t_tuple		normal;
	int			inside;
	t_tuple		over_point;
}	t_comps;

typedef struct s_camera
{
	int			hsize;
	int			vsize;
	double		field_of_view;
	double		pixel_size;
	double		half_width;
	double		half_height;
	t_tuple		origin;
	t_tuple		orientation;
	t_matrix	transform;
	t_matrix	inverse;
}	t_camera;

typedef struct s_image
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_camera	*c;
	t_world		*w;
	t_image		*img;
}	t_data;

typedef struct s_transform_aux{
	t_tuple		sub;
	t_tuple		forward;
	t_tuple		normal_up;
	t_tuple		left;
	t_tuple		true_up;
	t_tuple		neg;
}				t_transform_aux;

typedef struct s_sort_aux
{
	t_node	*temp;
	t_node	*ptr;
	t_node	*prev;
}	t_sort_aux;

typedef struct s_lighting_aux
{
	t_tuple	effective_c;
	t_tuple	light_v;
	t_tuple	ambient;
	t_tuple	diffuse;
	t_tuple	specular;
	t_tuple	sum;
	double	light_dot_normal;
	double	f_reflect_dot_eye;
}	t_lighting_aux;

typedef struct s_rt
{
	t_tuple		coordinates;
	t_tuple		orientation;
	t_tuple		color;
	double		diameter;
	double		height;
	double		brightness;
	double		fov;
}	t_rt;

// ############################################################################
// 					TUPLES
//#############################################################################
t_tuple			tuple(double x, double y, double z, double w);
t_tuple			vector(double x, double y, double z);
t_tuple			point(double x, double y, double z);
t_tuple			subtract(t_tuple a, t_tuple b);
t_tuple			negative(t_tuple v);
char			compare_tuples(t_tuple a, t_tuple b);
t_tuple			tuple_addition(t_tuple point, t_tuple vector);
t_tuple			multiply_tuple_by_scalar(
					t_tuple tuple_a, double times_to_multiply);
t_tuple			scalar_division(t_tuple tuple_a, double times_to_divide);
double			magnitude(t_tuple v);
t_tuple			normalize(t_tuple v);
t_tuple			cross(t_tuple a, t_tuple b);
double			dot(t_tuple v, t_tuple w);
t_tuple			color(double r, double g, double b);
t_tuple			multiply_colors(t_tuple c1, t_tuple c2);
t_tuple			reflect(t_tuple in, t_tuple normal);

// ############################################################################
// 					MATRIX
//#############################################################################
t_matrix		matrix(unsigned int n);
t_matrix		multiply_matrix(t_matrix matrix_a, t_matrix matrix_b);
t_tuple			multiply_matrix_with_tuple(t_matrix matrix_a, t_tuple tuple_a);
t_matrix		transpose_matrix(t_matrix matrix_a);
t_matrix		identity_matrix(unsigned int n);
t_matrix		translation(double x, double y, double z);
t_matrix		get_rotation_matrix(t_tuple orientation);
t_matrix		scaling(double x, double y, double z);
t_matrix		rotation_x(double radian);
t_matrix		rotation_y(double radian);
t_matrix		rotation_z(double radian);
t_matrix		cofactor_matrix(t_matrix m, int size);
int				compare_matrices(t_matrix matrix_a, t_matrix matrix_b);
void			free_matrix(t_matrix m);

// ############################################################################
// 					INVERSE
//#############################################################################

double			determinant_2x2_matrix(t_matrix matrix);
t_matrix		submatrix(t_matrix matrix, int row, int col);
int				get_size(t_matrix matrix);
double			minor(t_matrix matrix, int i, int j);
double			cofactor(t_matrix matrix, int i, int j);
double			get_determinant(t_matrix matrix);
t_matrix		inverse(t_matrix matrix);

// ############################################################################
// 					OBJECTS
//#############################################################################

void			append_object(t_object **head, t_object **new);
void			add_object(t_world *w, t_object *obj);
t_sphere		*create_sphere(void);
t_plane			*create_plane(void);
t_object		*create_object(char shape);
t_cylinder		*create_cylinder(void);
void			free_object(t_object *object);
void			free_sphere(t_sphere *s);
t_material		*material(void);
void			free_material(t_material *m);

// ############################################################################
// 					RENDER
//#############################################################################

void			render(t_data *data);
t_tuple			color_at(t_world *w, t_ray *r);
t_tuple			lighting(t_lighting *l);
t_tuple			light_vector(t_lighting *l);
void			free_lighting(t_lighting *l);
t_comps			*prepare_computations(t_node *hit, t_ray *ray);
void			free_comps(t_comps *comps);
t_tuple			shade_hit(t_world *world, t_comps *comps);
char			is_shadowed(t_world *world, t_tuple point);
void			free_world(t_world *world);

// ############################################################################
// 					CAMERA
//#############################################################################

t_camera		*camera(int hsize, int vsize, double field_of_view);
t_matrix		view_transform(t_tuple from, t_tuple to, t_tuple direction);
void			free_camera(t_camera *c);

// ############################################################################
// 					INTERSECT
//#############################################################################

t_intersect		*intersect(t_object *object, t_ray *ray);
t_intersect		*intersect_sphere(t_object *object, t_ray *ray);
t_intersect		*intersect_plane(t_object *object, t_ray *ray);
t_intersect		*intersect_world(t_world *world, t_ray *ray);
t_intersect		*intersect_cylinder(t_object *object, t_ray *ray);
t_node			*new_intersection(double t, t_object *object);
t_intersect		*add_intersection_to_list(t_intersect *list, t_node *new);
int				intersect_lst_size(t_node *head);
void			free_intersections(t_intersect *list);
t_node			*hit(t_intersect *xs);
t_tuple			normal_at(t_object *object, t_tuple point);
void			append_node(t_node **head, t_node *new);
t_tuple			local_normal_at(t_object *object, t_tuple local_point);
void			ft_swap(void *a, void *b);

// ############################################################################
// 					RAY
//#############################################################################

t_ray			*create_ray(t_tuple origin, t_tuple direction);
t_ray			*ray_for_pixel(t_camera *c, double px, double py);
t_ray			*transform_ray(t_ray *ray, t_matrix matrix);
t_tuple			get_point_position(t_ray *ray, double t);
void			free_ray(t_ray *ray);

// ############################################################################
// 					ALL
//#############################################################################

char			start_mlx(t_data *data);
void			set_mlx_hooks(t_data *data);
int				repeat_image(t_data *data);
int				handle_keypress(int keysym, t_data *data);
int				make_scene(t_data *data);
void			free_scene(t_data *data);
t_world			*create_world(void);
void			ft_free_ptr(void **ptr);

// ############################################################################
// 					PARSING
//#############################################################################

t_tuple			validate_color(char *str);
double			validate_angle(char *angle);
t_tuple			validate_coordinates(char *str);
t_tuple			validate_orientation(char *str);
char			validate_c(char *element, t_camera **cam);
char			validate_a(char *element, t_world *w);
char			validate_scene(char *scene_name, t_data *data);
double			*validate_tuple(char *str, double *n);
char			validate_l(char *element, t_point_light **light);
char			validate_sp(char *element, t_world *w);
char			validate_pl(char *element, t_world *w);
char			validate_cy(char *element, t_world *w);
double			get_double(char *str, int i, int j);
double			is_btwen_range(char *ratio, char *r0, char *r1);
void			free_split(char **split);
double			verify_and_get_double(char *str);
void			free_rt(t_rt *aux);
char			*get_scene(char *scene_name);
char			check_mandatory_elements(char **elements);
char			check_text_format(char **elements);
char			invalid(char *message, char *expected, char **infos, t_rt *aux);
double			ft_atof(const char *str);
char			is_double(char *str);
int				count_infos(char **infos);
void			set_transform(t_object *o, t_matrix transform);
char			error_msg(char *error_message, char *expected);
void			*error_msg_scene(char *error_message);
void			*clean_and_error_msg(char *msg, char *cpy_scene);
char			compare_doubles(double n1, double n2);
t_point_light	*point_light(t_tuple position, t_tuple intensity);

#endif
