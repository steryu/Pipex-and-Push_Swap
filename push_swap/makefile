# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 14:46:21 by svan-ass          #+#    #+#              #
#    Updated: 2022/02/09 09:45:14 by svan-ass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

SRCS		= main.c utils.c list_utils.c sort_small_stack.c clean.c indexing.c \
			check_args.c actions.c actions2.c actions3.c action_utils.c sort_big_stack.c 

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME): 	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0;32mDone!"

clean: 
	rm -f $(OBJS)

fclean: 	clean 
	rm -f $(NAME)
	@echo "\033[0;32mClean!"

re:			fclean all

.PHONY: 	all clean fclean re
