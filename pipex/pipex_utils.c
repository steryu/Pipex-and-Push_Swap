#include "pipex.h"

int	file_check(char *file, int in)
{
	if (in == 0)
	{
		if (access(file, F_OK))
		{
			write(2, "no such file or directory: ", 27);
			write(2, file, ft_strlen(file));
			write(2, "\n", 2);
		}
		else
			return (open(file, O_RDONLY));
	}
	else
		return (open(file, O_CREAT | O_RDWR | O_TRUNC, 0644));
	return (0);
}
