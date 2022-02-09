#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

int	main(int ac, char **ag, char **env);
int	file_check(char *file, int in);

#endif
