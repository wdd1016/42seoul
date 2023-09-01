
#include "../includes/cub3d.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		error_exit("Usage: ./cub3D <map.cub>");
	if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]))
		!= ft_strlen(argv[1]) - 4)
		error_exit("Map file extension must be .cub");
	ft_mlx_init(&data);
	ft_map_parsing(argv[1], &data);
	ft_set_hooks(&data);
	ft_print_image(&data);
	mlx_loop(data.mlx);
	exit(EXIT_SUCCESS);
}
