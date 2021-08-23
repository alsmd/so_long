#include "mlx/mlx.h"

int	main()
{
	void	*mlx;

	mlx = mlx_init();

	mlx_loop(mlx);
	return (0);
}
