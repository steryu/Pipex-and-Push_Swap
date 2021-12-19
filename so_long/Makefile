SRCS		= main.c read_map.c get_next_line/get_next_line.c

OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
MLXFLAGS 	= -framework OpenGL -framework AppKit

NAME		= so_long
LIBFT 		= ./libft/libft.a
MLX			= ./mlx/libmlx.a

all:		$(NAME)

$(LIBFT):
	$(MAKE) -C ./libft
$(MLX):
	$(MAKE) -C ./mlx

$(NAME): 	$(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
	@echo "\033[0;32mDone!"

clean: 
	rm -f $(OBJS) $(LIBFT) $(MLX)
	$(MAKE) -C libft/ clean
	$(MAKE) -C mlx/ clean

fclean: 	clean 
	rm -f $(NAME)
	$(MAKE) -C libft/ fclean
	@echo "\033[0;32mClean!"

re:			fclean all

.PHONY: 	all clean fclean re
