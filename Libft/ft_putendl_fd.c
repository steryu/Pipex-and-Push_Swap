#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		write(fd, &s[i], ft_strlen(s));
		write(fd, "\n", 1);
	}
}
