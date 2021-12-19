#include "so_long.h"

int	end_game(char *message)
{
	if (message)
	{
		printf("%s\n", message);
		exit(0);
	}
	else
		exit(0);
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel /8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		end_game("bye bye:)");
		mlx_destroy_window(data->mlx, data->mlx_win);
	}
	exit(0);
}

static void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		end_game("MLX initialization failed");
}

static void init_win(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, 720, 480, "so_long");
	if (!data.mlx_win == NULL)
		end_game("MLX couldn't create a new window");
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		width;
	int		height;

	if(argc != 2)
		printf("incorrect number of arguments\n");
	init_game(&data);
	read_map(argv[1]);
	init_win(&data);

	data->wall = mlx_xpm_file_to_image(data->mlx, "./images/ice_block.xpm", &width, &height);
	// load_pixel_art(&data)
	put_to_screen(&data);

	// data.img = mlx_new_image(data.mlx, 720, 480);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

	/* Setup hooks */
	mlx_hook(data.mlx_win, 2, 1L<<0, key_hook, &data);
	mlx_loop(data.mlx);

	free(data.mlx);
}
	// init_game(&data);
	// read_map_file(argv[1], &(data.map));
	// check_map(&data);
	// load_sprites(&data);
	// init_game_window(&data);
	// render_screen(&data);
	// setup_event_hooks(&data);
	// mlx_loop(data.mlx);
	// return (-1);