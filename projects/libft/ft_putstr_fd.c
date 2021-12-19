#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		counter;

	if (!s)
		return ;
	counter = 0;
	while ((s[counter] != '\0') && (s))
	{
		write(fd, &s[counter], 1);
		counter++;
	}
}
