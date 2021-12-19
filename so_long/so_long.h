#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	*wall;
}				t_data;

typedef struct s_map {
	int				x;
	int				y;
	char			c;
	struct s_map	*next;
}				t_map;

typedef struct s_tools{
	int		map_h;
	int		map_w;
	t_map	map;
}

int	main(int argc, char **argv);
int	read_map(char *map_file);
int	end_game(char *message);

//t_map_utils
t_map	*ft_mapnew(int x, int y, char c);
void	ft_mapadd_back(t_map **map, t_map *new);
t_map	*ft_maplast(t_map *map);
void	ft_mapclear(t_map **map, void(*del)(void *));

#endif
