/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:25:00 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/09/26 20:25:01 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

char	error_msg(char *error_message, char *expected)
{
	printf ("ERROR\n");
	printf ("%s, it must %s\n", error_message, expected);
	return (0);
}

void	*error_msg_scene(char *error_message)
{
	printf ("ERROR\n");
	printf ("%s\n", error_message);
	return (NULL);
}

void	*clean_and_error_msg(char *msg, char *cpy_scene)
{
	free(cpy_scene);
	return (error_msg_scene(msg));
}

void	free_rt(t_rt *rt)
{
	if (rt->coordinates)
		free(rt->coordinates);
	if (rt->color)
		free(rt->color);
	if (rt->orientation)
		free(rt->orientation);
	free(rt);
}

char	invalid(char *message, char *expected, char **infos, t_rt *rt)
{
	free_rt(rt);
	free_split(infos);
	return (error_msg(message, expected));
}
