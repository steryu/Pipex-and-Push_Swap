#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		counter;

	if (!s)
		return ;
	counter = 0;
	while (s[counter] != '\0')
	{
		write(fd, &s[counter], 1);
		counter++;
	}
	write(fd, "\n", 1);
}
