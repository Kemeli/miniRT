#include <minirt.h>

// double	**inverse(t_mat original_matrix)
// {
// 	t_mat	inversed_matrix;
// 	int			size;
// 	int			i;
// 	int			j;

// 	size = get_size(original_matrix);
// 	inversed_matrix = matrix(size);
// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			inversed_matrix[j][i] = cofactor(original_matrix, i, j)
// 				/ determinant(original_matrix);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (inversed_matrix);
// }

static t_mat	cofactor_matrix(t_mat m);
double	get_cofactor(t_mat m, int row, int column);
double	get_minor(t_mat m, int row, int column);
t_mat	get_submatrix(t_mat m, int row, int column);
t_mat	transposed_matrix(t_mat matrix);
t_bool	check_double_values(double a, double b);

double	get_determinant(t_mat m)
{
	double	det;
	int		i;

	if (m.size == 2)
		det = m.matrix[0][0] * m.matrix[1][1]
			- m.matrix[0][1] * m.matrix[1][0];
	else
	{
		det = 0;
		i = 0;
		while (i < m.size)
		{
			det += m.matrix[0][i] * get_cofactor(m, 0, i);
			i++;
		}
	}
	return (det);
}

t_mat	create_matrix(int size)
{
	t_mat	m;
	int			i;

	m.size = size;
	m.matrix = ft_calloc(size + 1, sizeof(double *));
	i = 0;
	while (i < size)
	{
		m.matrix[i] = ft_calloc(size + 1, sizeof(double));
		i++;
	}
	return (m);
}

t_bool	check_double_values(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (TRUE);
	return (FALSE);
}

t_mat	transposed_matrix(t_mat matrix)
{
	t_mat	transposed;
	int			i;
	int			j;

	transposed = create_matrix(matrix.size);
	i = 0;
	while (i < matrix.size)
	{
		j = 0;
		while (j < matrix.size)
		{
			transposed.matrix[i][j] = matrix.matrix[j][i];
			j++;
		}
		i++;
	}
	return (transposed);
}

t_mat	get_submatrix(t_mat m, int row, int column)
{
	t_mat	submatrix;
	int			i;
	int			j;
	int			k;
	int			l;

	submatrix = create_matrix(m.size - 1);
	i = -1;
	k = 0;
	while (++i < submatrix.size)
	{
		j = -1;
		l = 0;
		if (k == row)
			k++;
		while (++j < submatrix.size)
		{
			if (l == column)
				l++;
			submatrix.matrix[i][j] = m.matrix[k][l];
			l++;
		}
		k++;
	}
	return (submatrix);
}

double	get_minor(t_mat m, int row, int column)
{
	t_mat	submatrix;
	double		minor;

	submatrix = get_submatrix(m, row, column);
	minor = get_determinant(submatrix);
	free_matrix(submatrix.matrix);
	return (minor);
}

double	get_cofactor(t_mat m, int row, int column)
{
	double	minor;

	minor = get_minor(m, row, column);
	if ((column + row) % 2 == 0)
		return (minor);
	else
		return ((-1) * minor);
}

static t_mat	cofactor_matrix(t_mat m)
{
	t_mat	cofactor;
	int			i;
	int			j;

	cofactor = create_matrix(m.size);
	i = -1;
	while (++i < m.size)
	{
		j = -1;
		while (++j < m.size)
			cofactor.matrix[i][j] = get_cofactor(m, i, j);
	}
	return (cofactor);
}

t_matrix	inverse(t_matrix matrix)
{
	t_mat	cofactor;
	t_mat	inverse;
	t_mat	m;
	double		determinant;
	int			i;
	int			j;

	m.matrix = matrix;
	m.size = get_size(m.matrix);
	determinant = get_determinant(m);
	if (check_double_values(determinant, 0))
		return (identity_matrix(m.size));
	cofactor = cofactor_matrix(m);
	inverse = transposed_matrix(cofactor);
	free_matrix(cofactor.matrix);
	i = 0;
	while (i < inverse.size)
	{
		j = 0;
		while (j < inverse.size)
		{
			inverse.matrix[i][j] /= determinant;
			j++;
		}
		i++;
	}
	return (inverse.matrix);
}
