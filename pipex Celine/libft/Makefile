# -*- Makefile -*-
CC = gcc

CFLAGS = -Wall -Werror -Wextra

SOURCES = ft_atoi.c ft_split.c ft_striteri.c ft_strnstr.c ft_strrchr.c ft_tolower.c  \
ft_toupper.c ft_strmapi.c ft_itoa.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c \
ft_strtrim.c ft_strjoin.c ft_substr.c ft_strdup.c ft_bzero.c ft_calloc.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \

REG_OBJFILES = $(SOURCES:.c=.o)

BONUS_SRC = ft_lstmap.c ft_lstiter.c ft_lstclear.c ft_lstdelone.c \
ft_lstadd_back.c ft_lstlast.c ft_lstsize.c ft_lstadd_front.c ft_lstnew.c

BONUS_OBJS = $(BONUS_SRC:.c=.o)

NAME = libft.a

ifdef WITH_BONUS
OBJFILES = $(REG_OBJFILES) $(BONUS_OBJS)
else
OBJFILES = $(REG_OBJFILES)
endif

all: $(NAME)

$(NAME): $(OBJFILES) 
	ar -r $(NAME) $(OBJFILES) 

bonus:
	@$(MAKE) WITH_BONUS=1
	  
clean: 
	rm -f $(REG_OBJFILES) $(BONUS_OBJS)

fclean: clean
	rm -f *.a

re: fclean all

.PHONY: all bonus clean fclean re
