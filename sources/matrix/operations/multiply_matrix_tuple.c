#include <minirt.h>

t_tuple	multiply_matrix_with_tuple(t_matrix matrix_A, t_tuple tuple_A)
{
	t_tuple	result;
	double	sum[4];
	double	product;
	int		row;
	int		counter;

	row = 0;
	while (row < 4)
	{
		product = 0;
		counter = 0;
		while (counter < 4)
		{
			product += matrix_A[row][counter] * tuple_A[counter];
			counter++;
		}
		sum[row] = product;
		row++;
	}
	result = tuple(sum[0], sum[1], sum[2], sum[3]);
	return (result);
}
