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

static t_tuple	ligth_vector(t_lighting *l)
{
	t_tuple	sub;
	t_tuple	light_v;

	sub = subtract(l->light->position, l->position);
	light_v = normalize(sub);
	free(sub);
	return (light_v);
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

static void	free_aux(t_aux *aux)
{
	free(aux->effective_c);
	free(aux->light_v);
	free(aux->ambient);
	free(aux->diffuse);
	free(aux->specular);
	free(aux->sum);
	free(aux);
}

t_tuple	lighting(t_lighting *l)
{
	t_aux	*aux;
	t_tuple	response;
	t_tuple	ambient;

	aux = ft_calloc(1, sizeof(t_aux));
	aux->effective_c = multiply_colors(l->material->color, l->light->intensity);
	ambient = multiply_tuple_by_scalar(aux->effective_c, l->material->ambient);
	if (l->in_shadow)
	{
		free_aux(aux);
		return(ambient);
	}
	aux->light_v = ligth_vector(l);
	aux->light_dot_normal = dot(aux->light_v, l->normal);
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
	aux->sum = tuple_addition(ambient, aux->diffuse);
	response = tuple_addition(aux->sum, aux->specular);
	free_aux(aux);
	free(ambient);
	return (response);
}
