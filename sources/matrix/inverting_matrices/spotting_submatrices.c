#include "minirt.h"

int	get_size(float **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

float	**submatrix(float **original_matrix, int row, int col)
{
	int		i;
	int		j;
	int		size;
	float	**submatrix;

	size = get_size(original_matrix);
	submatrix = matrix(size - 1);
	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - 1)
		{
			if (i < row && j < col)
				submatrix[i][j] = original_matrix[i][j];
			else if (i < row && j >= col)
				submatrix[i][j] = original_matrix[i][j + 1];
			else if (i >= row && j < col)
				submatrix[i][j] = original_matrix[i + 1][j];
			else if (i >= row && j >= col)
				submatrix[i][j] = original_matrix[i + 1][j + 1];
		}
	}
	return (submatrix);
}
