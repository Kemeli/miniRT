#include <minirt.h>

typedef struct s_aux
{
	t_tuple	effective_c;
	t_tuple	light_v;
	t_tuple	ambient;
	t_tuple	diffuse;
	t_tuple	specular;
	t_tuple	sum;
	float	light_dot_normal;
	float	f_reflect_dot_eye;
}	t_aux;

static void	free_aux(t_aux *aux)
{
	free(aux->effective_c);
	free(aux->light_v);
	free(aux->ambient);
	if(aux && aux->diffuse)
		free(aux->diffuse);
	free(aux->specular);
	free(aux->sum);
	free(aux);
}

static float	reflect_dot_eye(t_lighting *l, t_tuple light_v)
{
	t_tuple	neg;
	t_tuple	reflect_v;
	float	reflect_dot_eye;

	neg = negative(light_v);
	reflect_v = reflect(neg, l->normal);
	reflect_dot_eye = dot(reflect_v, l->eye);
	free(reflect_v);
	free(neg);
	return (reflect_dot_eye);
}

static t_tuple	calculate_specular(t_lighting *l, float ref_dot_eye)
{
	t_tuple	specular;
	float	factor;

	if (ref_dot_eye <= 0)
		specular = color(0, 0, 0);
	else
	{
		factor = pow(ref_dot_eye, l->material->shininess);
		specular = multiply_tuple_by_scalar(
				l->light->intensity,
				l->material->specular * factor
				);
	}
	return (specular);
}

static void	get_difuse_and_specular(t_aux *aux, t_lighting *l)
{
	if (aux->light_dot_normal < 0)
	{
		aux->diffuse = color(0, 0, 0);
		aux->specular = color(0, 0, 0);
	}
	else
	{
		aux->diffuse = multiply_tuple_by_scalar(aux->effective_c,
				l->material->diffuse * aux->light_dot_normal);
		aux->f_reflect_dot_eye = reflect_dot_eye(l, aux->light_v);
		aux->specular = calculate_specular(l, aux->f_reflect_dot_eye);
	}
}

static t_tuple	multiply_color(t_tuple color, t_tuple amb)
{
	t_tuple	response;

	response = ft_calloc(3, sizeof(float));
	response[0] = color[0] * amb[0];
	response[1] = color[1] * amb[1];
	response[2] = color[2] * amb[2];
	return (response);
}

t_tuple	lighting(t_lighting *l)
{
	t_aux	*aux;
	t_tuple	response;
	t_tuple	ambient;

	aux = ft_calloc(1, sizeof(t_aux));
	aux->effective_c = multiply_colors(l->material->color, l->light->intensity);
	ambient = multiply_color(aux->effective_c, l->material->ambient);
	if (l->in_shadow)
	{
		free_aux(aux);
		return (ambient);
	}
	aux->light_v = ligth_vector(l);
	aux->light_dot_normal = dot(aux->light_v, l->normal);
	get_difuse_and_specular(aux, l);
	aux->sum = tuple_addition(ambient, aux->diffuse);
	response = tuple_addition(aux->sum, aux->specular);
	free_aux(aux);
	free(ambient);
	return (response);
}
