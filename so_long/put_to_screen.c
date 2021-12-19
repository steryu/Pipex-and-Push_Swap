int		put_to_screen(t_data *data)
{
	int y;
	int x;

	y = 0;
	while (y < 480)
	{
		x = 0;
		while (x < 720)
		{
			pixel_put(&data, x, y, 0xffebcd);
			x++;
		}
		y++;
	}
	while (map)
	{
		if (map->c == '1')
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.wall.img, map->x, map->y);
		map = map->next;
	}
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
}