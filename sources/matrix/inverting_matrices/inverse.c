#include <minirt.h>

t_matrix	get_inverse(t_matrix inverse, int size, double determinant)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			inverse[i][j] /= determinant;
			j++;
		}
		i++;
	}
	return (inverse);
}

t_matrix	inverse(t_matrix matrix)
{
	t_matrix	cofactor;
	t_matrix	inverse;
	double		determinant;
	int			size;

	size = get_size(matrix);
	determinant = get_determinant(matrix);
	if (compare_doubles(determinant, 0))
		return (identity_matrix(size));
	cofactor = cofactor_matrix(matrix, size);
	inverse = transpose_matrix(cofactor);
	free_matrix(cofactor);
	return (get_inverse(inverse, size, determinant));
}
