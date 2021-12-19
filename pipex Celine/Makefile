# -*- Makefile -*-
CC = gcc

CFLAGS = -Wall -Werror -Wextra

SOURCES = pipex.c pipex_utils.c

NAME = pipex

LIBFT = ./libft/libft.a 

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(SOURCES) $(LIBFT)
	$(CC) $(CFLAGS) $(SOURCES) $(LIBFT) -o $(NAME)
	  
clean: 
	make clean -C ./libft

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
