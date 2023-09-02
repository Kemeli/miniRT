#include <minirt.h>

double	**inverse(t_matrix original_matrix)
{
	t_matrix	inversed_matrix;
	int			size;
	int			i;
	int			j;

	size = get_size(original_matrix);
	inversed_matrix = matrix(size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			inversed_matrix[j][i] = cofactor(original_matrix, i, j)
				/ determinant(original_matrix);
			j++;
		}
		i++;
	}
	return (inversed_matrix);
}
