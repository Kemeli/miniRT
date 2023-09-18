#include <minirt.h>

t_matrix	inverse(t_matrix matrix)
{
	t_matrix	cofactor;
	t_matrix	inverse;
	double	determined;
	int		i;
	int		j;
	int		size;

	size = get_size(matrix);
	determined = determinant(matrix);
	if (compare_doubles(determined, 0))
		return (identity_matrix(size));
	cofactor = cofactor_matrix(matrix, size);
	inverse = transpose_matrix(cofactor);
	free_matrix(cofactor);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			inverse[i][j] /= determined;
			j++;
		}
		i++;
	}
	return (inverse);
}
