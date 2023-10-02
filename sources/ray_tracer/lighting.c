/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:26:18 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:26:18 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	free_aux(t_lighting_aux *aux)
{
	free(aux->effective_c);
	free(aux->light_v);
	if (aux && aux->diffuse)
		free(aux->diffuse);
	free(aux->specular);
	free(aux->sum);
}

static double	reflect_dot_eye(t_lighting *l, t_tuple light_v)
{
	t_tuple	neg;
	t_tuple	reflect_v;
	double	reflect_dot_eye;

	neg = negative(light_v);
	reflect_v = reflect(neg, l->normal);
	reflect_dot_eye = dot(reflect_v, l->eye);
	free(reflect_v);
	free(neg);
	return (reflect_dot_eye);
}

static t_tuple	calculate_specular(t_lighting *l, double ref_dot_eye)
{
	t_tuple	specular;
	double	factor;

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

static void	get_difuse_and_specular(t_lighting_aux *aux, t_lighting *l)
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

t_tuple	lighting(t_lighting *l)
{
	t_lighting_aux	aux;
	t_tuple			response;
	t_tuple			ambient;

	aux.effective_c = multiply_colors(l->material->color, l->light->intensity);
	ambient = multiply_colors(aux.effective_c, l->material->ambient);
	if (l->in_shadow)
	{
		free(aux.effective_c);
		return (ambient);
	}
	aux.light_v = light_vector(l);
	aux.light_dot_normal = dot(aux.light_v, l->normal);
	get_difuse_and_specular(&aux, l);
	aux.sum = tuple_addition(ambient, aux.diffuse);
	response = tuple_addition(aux.sum, aux.specular);
	free_aux(&aux);
	free(ambient);
	return (response);
}
