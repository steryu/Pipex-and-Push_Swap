#include "so_long.h"

int	check_if_map_exists(char *map_file)
{
	char	*ber; 
	size_t	file_length;

	file_length = ft_strlen(map_file);
	ber = ft_strnstr(map_file, ".ber", file_length);
	if (ber)
	{
		return(1);
	}
	end_game("Invalid map, file extension must end with '.ber' :)");
	return(0);
}

int	read_map(t_tools *tools, char *map_file)
{
	int		fd;
	char	*new_line;
	t_map	*map;
	t_map	node;
	int		x;

	check_if_map_exists(map_file);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		end_game("Failed to open map file");
	new_line = get_next_line(fd);
	if (!new_line)
		end_game("Failed to read from map file");
	x = 0;
	while (new_line[x])
	{
		node = ft_mapnew(x, 0, new_line[x]);
		if (!node)
			return (NULL);
		ft_mapadd_back(&map, node);
		x++;
	}
	tools->map = map;
	w = x;
	printf("%d", fd);
	close(fd);
	return (0);
}
