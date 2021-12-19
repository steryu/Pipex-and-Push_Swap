# -*- Makefile -*-
CC = gcc

CFLAGS = -Wall -Werror -Wextra

SOURCES = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c print_hex.c print_p.c print_u.c

REG_OBJFILES = $(SOURCES:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(REG_OBJFILES) 
	ar -r $(NAME) $(REG_OBJFILES) 
	  
clean: 
	rm -f $(REG_OBJFILES)

fclean: clean
	rm -f *.a

re: fclean all

.PHONY: all clean fclean re
