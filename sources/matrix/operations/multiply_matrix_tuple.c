#include <minirt.h>

t_tuple	multiply_matrix_with_tuple(float **matrix_A, t_tuple tuple_A)
{
	t_tuple	result;
	float	sum[4];
	float	product;
	int		row;
	int		counter;

	row = 0;
	counter = 0;
	while (row < 4)
	{
		product = 0;
		counter = 0;
		while(counter < 4)
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
