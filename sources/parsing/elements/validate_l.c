#include <minirt.h>

static char	validate_l_element(char *str, char type, t_teste *aux)
{
	if (type == 'l')
	{
		aux->coordinates = validate_coordinates(str);
		if (!aux->coordinates)
			return(0);
	}
	else if (type == 'b')
	{
		aux->brightness = is_btwen_range(str, "0", "1");
		if (aux->brightness == -1)
			return(0);
	}
	return(1);
}

char	validate_l(char *element, t_point_light **light)
{
	char		**infos;
	t_tuple		c;
	t_teste		*aux;

	aux = ft_calloc(1, sizeof(t_teste));
	infos = ft_split(element, ' ');
	if (count_infos(infos) != 3)
		return(print_error("invalid amount of light infos", infos, aux));
	if(!validate_l_element(infos[1], 'l', aux))
		return(print_error("invalid light position", infos, aux));
	if(!validate_l_element(infos[2], 'b', aux))
		return(print_error("invalid light brightness", infos, aux));
	c = color(1, 1, 1);
	*light = point_light(
		point(aux->coordinates[0], aux->coordinates[1], aux->coordinates[2]),
		multiply_tuple_by_scalar(c, aux->brightness));
	free_split(infos);
	free(c);
	free_teste(aux);
	return(1);
}
