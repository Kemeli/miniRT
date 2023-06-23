#include "minirt.h"

int	main()
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	x = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "hello mlx");
	while (x < 250)
	{
		y = 0;
		while (y < 500)
		{
			mlx_pixel_put(mlx, win, x, y, 200);
			y++;
		}
		x++;
	}
	mlx_loop(mlx);
}
